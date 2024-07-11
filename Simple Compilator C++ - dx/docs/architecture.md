# Simple Compiler Architecture

## Overview

This document provides an overview of the architecture of the Simple Compiler project.

## Components

### Lexer

The Lexer is responsible for tokenizing the input source code. It converts the raw source text into a sequence of tokens that can be used by the parser.

### Parser

The Parser takes the tokens produced by the Lexer and generates an Abstract Syntax Tree (AST). The AST represents the syntactic structure of the source code.

### AST (Abstract Syntax Tree)

The AST is a tree representation of the abstract syntactic structure of the source code. Each node of the tree denotes a construct occurring in the source code.

### Code Generator

The Code Generator traverses the AST and produces intermediate code. This code can be further processed, optimized, or executed.

### Error Handling

The Error Handling module is responsible for managing and reporting errors during the compilation process.

## Flow

1. **Lexical Analysis:** The source code is tokenized by the Lexer.
2. **Syntax Analysis:** The Parser uses the tokens to build the AST.
3. **Code Generation:** The Code Generator produces intermediate code from the AST.
