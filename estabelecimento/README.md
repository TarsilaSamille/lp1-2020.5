# Atividade 05 - Linguagem de Programação l - Semestre suplementar 2020.5
## Realizada em dupla por:
> - João Victor da Silva Saturnino
> - Társila Samille Santos da Silveira
## O Programa
O Programa consiste em um supermercado, onde o usuário pode checar os produtos existentes, fazer compra destes produtos e demais operações presentes no menu. Possui 4 classes principais: Cliente, Estabelecimento, Fornecedor e Produto. Também possui uma classe vector_supermercado, que tem como objetivo criar um vector genérico para armazenar os diferentes tipos de atributos utilizados em nosso sistema.
 >observação: No menu, é possível adicionar vários produtos de uma vez só, desde que estejam separados por vírgula 

## Como compilar
- Dentro da pasta "estabeleciemento", deve-se rodar o seguinte comando:
 > cmake -S . -Bbuild
- Isso irá gerar a pasta Build. Após isto, deve-se copiar as pastas supemercado e restaurante para dentro da pasta Build. Feito isso, deve-se rodar o seguinte comando:
 > make
- Isto irá gerar o nosso executável. Após isso, o programa é inciado com o seguinte comando:
 > ./estabeleciemento