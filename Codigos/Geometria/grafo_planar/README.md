# [Enumerar Faces De Um Grafo Planar](planar_graph_faces.cpp)

Encontra as faces de grafo planar **conexo** em $\mathcal{O}(n \log n)$. Retorna os conjunto de ponto de cada face. Caso esteja no sentido horário corresponde a uma face externa, caso esteja no sentido anti horário é uma face interna.

**Obs**: utiliza a propria primitiva de ponto. 

# [Enumerar Faces De Um Grafo Planar pela interseção de retas](line_segment_planar_graph.cpp)

Retorna as faces de grafo planar a partir de um cojunto de segmentos de reta em $\mathcal{O}(n^2 \log n)$.

# [Localização de Pontos](point_location_planar_graph.cpp)

Encontra de forma **offline** a qual face dada ponto pertence em $\mathcal{O}(Q \log n)$.