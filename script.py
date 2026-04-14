import random
import string
import os

# 1. Cria uma pasta para organizar os ficheiros gerados, se ela não existir
pasta_destino = "dados_teste"
if not os.path.exists(pasta_destino):
    os.makedirs(pasta_destino)

# 2. Define os tamanhos das entradas que o professor pede para testar
# Nota: Removi os 100 milhões para já, para não encher o seu disco rígido e não demorar horas. 
# Quando o código em C e Java estiver perfeito, você pode adicionar 1000000 ou mais à lista.
tamanhos = [100, 1000, 10000, 100000]

print("Iniciando a geração de dados. Isto pode demorar uns segundos para os ficheiros maiores...")

for tamanho in tamanhos:
    print(f"A gerar ficheiros com {tamanho} itens...")

    # --- PARTE DOS INTEIROS ---
    nome_ficheiro_int = f"{pasta_destino}/inteiros_{tamanho}.txt"
    
    with open(nome_ficheiro_int, 'w') as arq_int:
        for _ in range(tamanho):
            # Gera um número entre 1 e 1 milhão
            numero = random.randint(1, 1000000)
            arq_int.write(f"{numero}\n")

    # --- PARTE DAS STRINGS ---
    nome_ficheiro_str = f"{pasta_destino}/strings_{tamanho}.txt"
    
    with open(nome_ficheiro_str, 'w') as arq_str:
        for _ in range(tamanho):
            # Escolhe 10 letras aleatórias (maiúsculas/minúsculas) e junta-as numa palavra
            palavra = ''.join(random.choices(string.ascii_letters, k=10))
            arq_str.write(f"{palavra}\n")

print("\nGeração concluída com sucesso! Verifique a pasta 'dados_teste'.")