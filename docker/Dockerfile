# Dockerfile para geração do PDF do Almanaque Brute
# Baseado no Ubuntu 24.04 (mesmo ambiente do GitHub Actions)

FROM ubuntu:24.04

# Evita prompts interativos durante instalação
ENV DEBIAN_FRONTEND=noninteractive

# Atualiza sistema e instala dependências
RUN apt-get update && apt-get install -y \
    # Python
    python3 \
    python3-pip \
    # LaTeX dependencies (mesmo do GitHub Actions)
    texlive-latex-base \
    texlive-latex-extra \
    texlive-lang-portuguese \
    cm-super \
    rubber \
    # Ferramentas úteis
    git \
    clang-format \
    && rm -rf /var/lib/apt/lists/*

# Define diretório de trabalho
WORKDIR /workspace

# Define usuário não-root para segurança
RUN useradd -m -s /bin/bash almanaque && \
    chown -R almanaque:almanaque /workspace

USER almanaque

# Comando padrão
CMD ["python3", ".github/scripts/pdfer.py"]
