# Makefile para Almanaque Brute
# Autor: BRUTE UDESC

.PHONY: help pdf clean format check-format docker-pdf install-deps

# Configurações
PYTHON := python3
PDFER_SCRIPT := .github/scripts/pdfer.py
CONTAINER_ENGINE := podman
CONTAINER_IMAGE := almanaque-builder
LATEX_DIR := LaTeX
PDF_DIR := PDF

# Target padrão
help: ## Mostra esta ajuda
	@echo "Almanaque Brute - Makefile"
	@echo ""
	@echo "Targets disponíveis:"
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "  %-15s %s\n", $$1, $$2}' $(MAKEFILE_LIST)

pdf: ## Gera o PDF do almanaque usando container
	@echo "🔨 Gerando PDF do almanaque usando $(CONTAINER_ENGINE)..."
	@if ! $(CONTAINER_ENGINE) image inspect $(CONTAINER_IMAGE) >/dev/null 2>&1; then \
		echo "📦 Imagem não encontrada. Construindo..."; \
		$(MAKE) container-build; \
	fi
	@$(CONTAINER_ENGINE) run --rm \
		-v "$(PWD):/workspace:Z" \
		-w /workspace \
		$(CONTAINER_IMAGE) \
		python3 .github/scripts/pdfer.py
	@echo "✅ PDF gerado com sucesso em $(PDF_DIR)/Almanaque.pdf"

clean: ## Remove arquivos temporários do LaTeX
	@echo "🧹 Limpando arquivos temporários..."
	@find $(LATEX_DIR) -name "*.aux" -delete 2>/dev/null || true
	@find $(LATEX_DIR) -name "*.log" -delete 2>/dev/null || true
	@find $(LATEX_DIR) -name "*.out" -delete 2>/dev/null || true
	@find $(LATEX_DIR) -name "*.toc" -delete 2>/dev/null || true
	@find $(LATEX_DIR) -name "*.rubbercache" -delete 2>/dev/null || true
	@find $(LATEX_DIR) -name "*.tex" -not -name "INICIO_*.tex" -not -name "STL.tex" -not -name "Teorico.tex" -delete 2>/dev/null || true
	@echo "✅ Limpeza concluída"

format: ## Formata todos os arquivos C++ usando container
	@echo "🎨 Formatando arquivos C++ usando $(CONTAINER_ENGINE)..."
	@if ! $(CONTAINER_ENGINE) image inspect $(CONTAINER_IMAGE) >/dev/null 2>&1; then \
		echo "📦 Imagem não encontrada. Construindo..."; \
		$(MAKE) container-build; \
	fi
	@$(CONTAINER_ENGINE) run --rm \
		-v "$(PWD):/workspace:Z" \
		-w /workspace \
		$(CONTAINER_IMAGE) \
		find Codigos -name "*.cpp" -exec clang-format -i {} \;
	@echo "✅ Formatação concluída"

check-format: ## Verifica se os arquivos C++ estão formatados corretamente usando container
	@echo "🔍 Verificando formatação dos arquivos C++..."
	@if ! $(CONTAINER_ENGINE) image inspect $(CONTAINER_IMAGE) >/dev/null 2>&1; then \
		echo "📦 Imagem não encontrada. Construindo..."; \
		$(MAKE) container-build; \
	fi
	@if $(CONTAINER_ENGINE) run --rm \
		-v "$(PWD):/workspace:Z" \
		-w /workspace \
		$(CONTAINER_IMAGE) \
		find Codigos -name "*.cpp" -exec clang-format --dry-run --Werror {} \; 2>/dev/null; then \
		echo "✅ Todos os arquivos estão formatados corretamente"; \
	else \
		echo "❌ Alguns arquivos precisam ser formatados. Execute 'make format'"; \
		exit 1; \
	fi

container-build: ## Constrói a imagem do container para geração do PDF
	@echo "📦 Construindo imagem $(CONTAINER_ENGINE)..."
	@$(CONTAINER_ENGINE) build -t $(CONTAINER_IMAGE) -f docker/Dockerfile .
	@echo "✅ Imagem construída: $(CONTAINER_IMAGE)"

container-clean: ## Remove a imagem do container
	@echo "🧹 Removendo imagem $(CONTAINER_IMAGE)..."
	@$(CONTAINER_ENGINE) rmi $(CONTAINER_IMAGE) 2>/dev/null || true
	@echo "✅ Imagem removida"

all: clean pdf ## Executa limpeza e gera PDF

# Debug targets
debug-env: ## Mostra informações do ambiente
	@echo "🔍 Informações do ambiente:"
	@echo "Container Engine: $$($(CONTAINER_ENGINE) --version 2>/dev/null || echo 'Não instalado')"
	@echo "Imagem $(CONTAINER_IMAGE): $$($(CONTAINER_ENGINE) image inspect $(CONTAINER_IMAGE) >/dev/null 2>&1 && echo 'Disponível' || echo 'Não construída')"
	@echo "PWD: $(PWD)"
