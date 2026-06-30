cmake_minimum_required(VERSION 4.2)
project(Programacao_Competitiva)

set(CMAKE_CXX_STANDARD 14)

add_executable(Programacao_Competitiva
        Algoritmos/Estrutura_de_Dados/teste.cpp
        Algoritmos/Geometria/teste.cpp
        Algoritmos/Grafos/teste.cpp
        Algoritmos/Matematica/teste.cpp
        Maratonas_Anteriores/teste.cpp
        Solucoes/Codeforces/Geometria/teste.cpp
        Solucoes/Codeforces/Grafos/teste.cpp
        Solucoes/Codeforces/Matematica/teste.cpp
        Solucoes/Kattis/teste.cpp
        Solucoes/UVA/teste.cpp
        main.cpp
        "Solucoes/UVA/Grafos/Bicoloring - 10004.cpp"
        Algoritmos/Grafos/ArticulationVertexAndBridges.cpp
        Algoritmos/Grafos/Kosaraju_Tarjan.cpp
        "Solucoes/UVA/Grafos/Come and Go - 11838.cpp"
        "Solucoes/UVA/Grafos/Calling Circles - 247.cpp")
