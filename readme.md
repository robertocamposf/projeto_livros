# Sistema de Controle de Livros em C

Este projeto é um sistema simples de gerenciamento de acervo de livros desenvolvido em linguagem C para a disciplina de Programação Estruturada.

## Funcionalidades
- Leitura automática de base de dados (`livros.txt`).
- Adição de novos registros em memória usando `structs`.
- Busca de livros por código (Busca Linear).
- Ordenação de acervo por ano de publicação (Bubble Sort).

## Como compilar e executar

### Pré-requisitos
Ter um compilador C (como o GCC) instalado na máquina (MinGW no Windows ou nativo no Linux/Mac).

### Passos
1. Clone o repositório ou baixe os arquivos.
2. Certifique-se de que `main.c` e `livros.txt` estão na mesma pasta.
3. Abra o terminal na pasta dos arquivos e compile o código:
   gcc main.c -o sistema_livros
4. Execute o arquivo gerado após compilar: 
   .\sistema_livros.exe