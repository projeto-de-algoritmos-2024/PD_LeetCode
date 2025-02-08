class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # criamos um dicionario para fazer a estratégia de memoização, chamando de cache
        cache = {}

        # utilizamos uma busca em profundidade com backtracking para fazer o algoritmo
        def dfs(i,j):
            
            # sempre iremos retornar pelo cache dentro da busca em largura com backtracking
            # para reduzir o uso de memória, assim otimizando o algoritmo, únicas excessões serão 
            # quando o retorno for false ou precisar fazer a recursão ou for caso de extremidade
            if(i,j) in cache:
                return cache[(i,j)] 
            
            # caso de extremidade, ambos os ponteiros fora da analise
            if i >= len(s) and j >= len(p):
                return True
            # caso de extremidade, o j não está mais na solução, é necessário retornar falso
            if j >= len(p):
                return False
            # checa se a comparação é verdadeira tanto diretamente quanto por um "." no lugar
            match = i < len(s) and (s[i] == p[j] or p[j] == ".")
            # checa para o caracter "*" e adiciona ao cache
            if (j + 1) < len(p) and p[j + 1] == "*" :
                # adiciona ao cache de acordo com qual caracter está dando match com "*"
                # se em j, pula dois caracters e continua, se em i, faz a checagem do próximo 
                # e continua
                cache[(i,j)] = (dfs(i, j + 2) or (match and dfs(i + 1, j)))
                return cache[(i,j)]
            # continua a função, retornando para continuar ou falso caso precise finalizar 
            # e retornar falso
            if match:
                return dfs(i + 1, j + 1)
            return False
        
        return dfs(0,0)

