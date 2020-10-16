# Atividade 05 - Linguagem de Programação l - Semestre suplementar 2020.5
## Realizada em dupla por:
> - João Victor da Silva Saturnino
> - Társila Samille Santos da Silveira
## O Programa
O Programa consiste em um estabelecimento, onde o usuário pode escolher se quer fazer uso de um supermercado ou de um restaurante, através do menu inicial. Ao escolher Supermercado, o usuário pode checar os produtos existentes, fazer compra destes produtos e demais operações presentes no menu. Ao escolher Restaurante, o usuário pode checar o cardápio, fazer pedidos e demais operaçõeos presentes no menu. Possui 6 classes principais: Cliente, Estabelecimento, Fornecedor, Produto, Restaurante e Supermercado. Também possui uma classe vector_supermercado, que tem como objetivo criar um vector genérico para armazenar os diferentes tipos de atributos utilizados em nosso sistema. Além disso, o Main.cpp chama, de acordo com a opção do usuário, a classe appRestaurante ou appSupermercado. Há também uma classe Exceptions com métodos de exibição de mensagens no tratamento de exceções.
 >observação: No menu, é possível adicionar vários produtos de uma vez só, desde que estejam separados por vírgula 

## Como compilar
- Dentro da pasta "estabelecimento", deve-se rodar o seguinte comando:
 > cmake -S . -Bbuild
- Isso irá gerar a pasta Build. Após isto, deve-se copiar as pastas supemercado e restaurante para dentro da pasta Build. Feito isso, deve-se rodar o seguinte comando, dentro da pasta build:
 > make
- Isto irá gerar o nosso executável. Após isso, ainda dentro da pasta build, o programa é inciado com o seguinte comando:
 > ./estabelecimento

 ## Observações
 - O tratamento de exceções genéricas serão geradas apenas se for removido o comentário presente na classe que force o lançamento da exceção, pois o código roda de modo a não precisar lançá-las. O comenrário está presente em appRestaurante.cpp, appSupermercado.cpp e Main.cpp.