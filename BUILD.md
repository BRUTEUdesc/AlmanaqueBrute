# 🔨 Guia de Build - Almanaque Brute

Este documento descreve o novo fluxo de build melhorado para o Almanaque Brute.

## 🎯 Visão Geral

O novo sistema usa **containerização** para garantir builds consistentes e não requer instalação local de LaTeX ou ferramentas de formatação. Tudo roda em containers usando Podman/Docker.

## 📋 Pré-requisitos

- **Podman** (recomendado) ou Docker
- Make (geralmente já instalado no sistema)

## 🚀 Comandos Principais

### Gerar PDF
```bash
make pdf
```
- Constrói automaticamente a imagem do container se necessário
- Gera o PDF completo do almanaque
- Salva em `PDF/Almanaque.pdf`

### Limpar arquivos temporários
```bash
make clean
```

### Formatar código C++
```bash
make format
```
- Formata todos os arquivos `.cpp` usando clang-format
- Roda dentro do container (não precisa instalar localmente)

### Verificar formatação
```bash
make check-format
```
- Verifica se todos os arquivos estão formatados corretamente
- Útil para CI/CD

### Construir imagem do container
```bash
make container-build
```
- Constrói a imagem com todas as dependências LaTeX
- Baseada no Ubuntu 24.04 (mesmo ambiente do GitHub Actions)

### Remover imagem do container
```bash
make container-clean
```

### Executar tudo
```bash
make all
```
- Limpa arquivos temporários
- Gera o PDF

## 🏗️ Estrutura Melhorada

### Modularização LaTeX
- **`LaTeX/chapters/`**: Capítulos modulares (pragmas, constantes, etc.)
- **`LaTeX/STL.tex`**: Agora usa `\input{}` para incluir módulos
- **`Codigos/Extra/Pragmas/`**: Pragmas movidos para seção de código

### Organização de Código
- **Pragmas**: Agora em `Codigos/Extra/Pragmas/` com README próprio
- **Formatação**: Configuração `.clang-format` padronizada
- **Container**: Dockerfile com todas as dependências

## 🐳 Container

O container inclui:
- Ubuntu 24.04 LTS
- Python 3.12
- LaTeX completo (texlive-latex-base, texlive-latex-extra, etc.)
- Rubber (compilador LaTeX otimizado)
- clang-format 20
- Git

## 📝 Script Melhorado

O `pdfer.py` agora:
- ✅ Mostra progresso com emojis
- ✅ Usa rubber quando disponível, fallback para pdflatex
- ✅ Processa seções em ordem determinística
- ✅ Melhor tratamento de erros
- ✅ Limpeza automática de arquivos temporários

## 🔧 Configuração

### Podman vs Docker
O Makefile usa Podman por padrão. Para usar Docker:
```bash
# Edite o Makefile e mude:
CONTAINER_ENGINE := docker
```

### Formatação
A configuração está em `.clang-format`:
- Baseada no estilo LLVM
- Adaptada para competitive programming
- Linha máxima: 100 caracteres
- Indentação: 4 espaços

## 🚨 Solução de Problemas

### Container não encontrado
```bash
make container-build
```

### Erro de permissão (SELinux)
O Makefile usa `:Z` no volume mount para compatibilidade com SELinux.

### Erro de LaTeX
Verifique os logs no container. O script tenta rubber primeiro, depois pdflatex.

## 📊 Comparação: Antes vs Depois

| Aspecto | Antes | Depois |
|---------|-------|--------|
| **Dependências** | Instalar LaTeX localmente | Container com tudo |
| **Formatação** | Manual ou CI apenas | `make format` local |
| **Modularidade** | Tudo em arquivos grandes | Capítulos separados |
| **Build** | Script Python apenas | Makefile + Container |
| **Pragmas** | Misturado no STL.tex | Seção própria com código |
| **Consistência** | Depende do ambiente | Container padronizado |

## 🎉 Benefícios

1. **Zero instalação local**: Tudo roda em container
2. **Builds consistentes**: Mesmo ambiente do CI/CD
3. **Formatação automática**: clang-format integrado
4. **Modularidade**: LaTeX organizado em capítulos
5. **Melhor UX**: Progresso visual e mensagens claras
6. **Flexibilidade**: Funciona com Podman ou Docker

## 🤖 GitHub Actions Workflows

Os workflows do GitHub Actions usam a **mesma infraestrutura** do Makefile

### Workflows Disponíveis

#### 1. **Verificação de Formatação** (`clang-format-check.yml`)
- **Trigger**: Pull Requests para `main`
- **Função**: Verifica se código C++ está formatado corretamente
- **Container**: Usa o mesmo container do `make check-format`

#### 2. **Geração de PDF** (`generate_almanaque_pdf.yml`)
- **Trigger**: Push para `main`
- **Função**: Gera PDF automaticamente e cria PR com atualizações
- **Container**: Usa o mesmo container do `make pdf`

## 🔄 Workflow Recomendado

### Desenvolvimento Local
```bash
# 1. Criar branch
git checkout -b feat-minha-branch

# 2. Editar código
vim Codigos/Estruturas-de-Dados/Segment-Tree/segment_tree.cpp

# 2. Formatar
make format

# 3. Commitar e pushar as mudanças
git add Codigos/Estruturas-de-Dados/Segment-Tree/segment_tree.cpp
git commit -m "fix: fixed Segment Tree"
git push --set-upstream origin feat-minha-branch

# 4. Gerar o Pull Request
# Na interface do Github, crie o Pull Request e aguarde aprovação
```

---

**Dica**: Use `make help` para ver todos os comandos disponíveis localmente, ou acesse **Actions** no GitHub para executar comandos remotamente!

