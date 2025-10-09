CONTAINER_ENGINE ?= docker
BASE_IMAGE       ?= python:3.11-slim
LATEX_IMAGE      ?= almanaque-latex:latest
WORKDIR          ?= /workspace
APT_PACKAGES     ?= texlive-latex-base texlive-latex-recommended texlive-latex-extra texlive-fonts-recommended texlive-lang-portuguese lmodern latexmk rubber make git
DOCKERFILE       ?= containers/latex.Dockerfile

HOST_UID := $(shell id -u)
HOST_GID := $(shell id -g)

.PHONY: help pdf generate container-shell latex-image clean-image

help:
	@echo "Alvos disponíveis:"
	@echo "  make pdf              # Gera o PDF via container ($(CONTAINER_ENGINE))"
	@echo "  make generate         # Executa o gerador localmente (requer latex instalado na máquina)"
	@echo "  make container-shell  # Abre um shell no container já preparado"
	@echo "  make latex-image      # Constrói/atualiza a imagem de LaTeX"
	@echo "  make clean-image      # Remove a imagem local de LaTeX"

latex-image:
	@if ! $(CONTAINER_ENGINE) image inspect $(LATEX_IMAGE) >/dev/null 2>&1; then \
		echo ">> Construindo imagem $(LATEX_IMAGE)"; \
		$(CONTAINER_ENGINE) build \
			--build-arg BASE_IMAGE=$(BASE_IMAGE) \
			--build-arg APT_PACKAGES="$(APT_PACKAGES)" \
			-t $(LATEX_IMAGE) \
			-f $(DOCKERFILE) . ; \
	else \
		echo ">> Imagem $(LATEX_IMAGE) já presente (use clean-image para reconstruir à força)"; \
	fi

pdf: latex-image
	$(CONTAINER_ENGINE) run --rm \
		-e HOST_UID=$(HOST_UID) \
		-e HOST_GID=$(HOST_GID) \
		-v "$(PWD)":$(WORKDIR) \
		-w $(WORKDIR) \
		$(LATEX_IMAGE) \
		bash -lc "python3 .github/scripts/pdfer.py && \
			chown -R $$HOST_UID:$$HOST_GID PDF README.md LaTeX/main.tex LaTeX/generated 2>/dev/null || true"

generate:
	python3 .github/scripts/pdfer.py

container-shell: latex-image
	$(CONTAINER_ENGINE) run --rm -it \
		-e HOST_UID=$(HOST_UID) \
		-e HOST_GID=$(HOST_GID) \
		-v "$(PWD)":$(WORKDIR) \
		-w $(WORKDIR) \
		$(LATEX_IMAGE) \
		bash

clean-image:
	-$(CONTAINER_ENGINE) image rm $(LATEX_IMAGE)
