ARG BASE_IMAGE=python:3.11-slim
FROM ${BASE_IMAGE}

ARG APT_PACKAGES="texlive-latex-base texlive-latex-recommended texlive-latex-extra texlive-fonts-recommended texlive-lang-portuguese lmodern latexmk rubber make git"

ENV DEBIAN_FRONTEND=noninteractive \
    PIP_NO_CACHE_DIR=1

RUN apt-get update && \
    apt-get install -y --no-install-recommends ${APT_PACKAGES} && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
