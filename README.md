# Esp01
Conteúdo referente ao Módulo Wi-Fi Esp8266 Esp-01s Esp01s

## Link do produto: https://www.lojamekanus.com.br/produto/408427/



## O conteúdo do repositório é sempre relacionado ao tema do mesmo, podendo entretanto, não estar limitado a somente ao tema. 

## O material aqui contido não deve ser utilizado com finalidade comercial.

CONTROLE DE CARGAS IOT

Recentemente tivemos a oportunidade de gerar uma página html hospedada no código C++ usado para programar o Arduino, usado foi um ESP-01s. O ESP-01s era capaz de conectar-se a uma rede interna provida por um roteador e entrando com o IP em um navegador, é possível carregar nele a página gerada e enviar os comandos através da interface apresentada. No caso, uma página simples apresentava dois botões, que por sua vez, aguardava o comando humano para que o ESP-01 realizasse a tarefa.
No entanto, está tudo em uma rede interna. Nenhum dos dispositivos controlados estavam em uma outra rede. O termo “IOT” estava presente apenas como “meta” e não como realidade... Este problema estava com os dias contados!
Um dispositivo de rede precisava de um servidor MQTT para que pudesse estar disponível através da internet. Assim, uma pesquisa focada em encontrar um server MQTT gratuito iniciou-se. Dentre os diversos, encontramos um método até então, mais simples. Trata-se do Cayenne MQTT.
Cayenne é uma área de desenvolvimento IOT da myDevices, empresa focada em conectividade rápida e fácil, com mais de 400 soluções “plug-and-play” entre os diversos fabricantes de dispositivos tipos de conectividade wireless.
Diante da gama de produtos que a Mekanus possui, este método é o que melhor auxilia e conduz para a solução IOT, cito como exemplo o ESP-01,WEMOS, ESP8266 e o poderoso ESP32.
Então, vamos conectar?

O SKETCH
Uma das partes mais importantes do código é a biblioteca. Faz-se imprescindível que seja baixada e instalada na IDE. Acesse Sketch > Incluir Biblioteca > Gerenciar Biblioteca (ou simultaneamente pressione CTRL + SHIFT + I). Na caixa de texto, digite “Cayenne” e instale a biblioteca “CayenneMQTT”.
 
É recomendável que baixe toda a árvore de bibliotecas da Cayenne, disponível em https://github.com/myDevicesIoT/Cayenne-MQTT-Arduino.

USUÁRIO CAYENNE
Acesse https://mydevices.com/ , clique em “login” e escolha a opção “Cayenne”. Clique no botão vermelho logo abaixo.
Faça o registro de um novo usuário, conforme o e-mail e poderá iniciar. Confirme o e-mail. É importante isso!
Clique em “All Devices” e em seguida em “Generic ESP8266”. A título de curiosidade, sim, funciona também com o ESP8266 NodeMCU e Wemos.
Ao clicar no ícone/link do “Genenric ESP8266”, uma nova página será carregada com algumas informações importantes, conforme mostra na próxima imagem.
 
Estas informações devem ser inseridas no Sketch que será carregado no ESP-01. Nesse momento, já deveríamos saber preparar a IDE do Arduino para programar o ESP-01. Por esta razão, não vejo necessidade de voltar a este ponto.

RECOMENDAÇÃO IMPORTANTE PARA UMA CONEXÃO BEM SUCEDIDA:
Sua rede SSID deve possuir nome sem caracteres especiais ou numerais. Alguns roteadores que possuem duas velocidades, apresentam em seus nomes alguns termos como “2.4G” ou “5.0G” e isso dificulta a conexão adequada com o roteador. Ou seja, muito mal consegue fazer a conexão com uma rede interna. Seguindo...
Fazendo uso de um programador USB para ESP-01s, transferimos o código através do Arduino IDE.

O CÓDIGO
#include <CayenneMQTTESP8266.h>         // Inclui biblioteca específica para o ESP8266
#define CAYENNE_DEBUG                   // Inclui bibliotecas adicionais para debug
#define CAYENNE_PRINT Serial            // Define funções seriais
char ssid[] = "nome_da_sua_rede";                               // Nome da rede wifi
char password[]="senha_da_sua_rede";                            // Senha da rede wifi
char username[] = "código_username_fornecido_na_página";        // Username obtido nas configurações do Cayenne
char mqtt_password[] = "código_mqtt_fornecido_na_página";       // Senha de acesso ao MQTT
char cliend_id[] = "código_id_do_cliente_fornecido_na_página";  // Cliente ID

void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, mqtt_password, cliend_id, ssid, password);  //Inicia o Cayenne com as informações recebidas
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  //pinMode(0, OUTPUT);
  //digitalWrite(0, HIGH);
}
void loop() {
  Cayenne.loop();
}
CAYENNE_IN(0){
  //digitalWrite(0, !getValue.asInt()); 
}
CAYENNE_IN(2){
  digitalWrite(2, !getValue.asInt()); 
}

Depois de compilado, ainda no programador, o ESP-01s pode ser testado. Usaremos o LED embarcado na própria placa como teste. Como ele está ligado ao GPIO “2” do ESP-01, poderemos facilmente observar a reação.
Para que isso ocorra bem, precisamos preparar o dashboard. Naquela página dos códigos, clicamos no botão “Back” e então, uma página semelhante a esta a seguir, aparecerá. Dados pessoais foram ocultados, ok.
 
Vamos incluir um botão para controle do LED embarcado.
Clicamos alí em “Add new...”, em seguida clique em “Device/widget” e siga a mimica conforme indica a imagem abaixo: 

Clique em “Custom Widgets”. Selecione “Button” e abrirá o setup deste widget. Atribua um nome, indique a que dispositivo está conectado. Defina o tipo de dados que ele operará. Defina a unidade (tipo de lógica usada). Defina o canal e escolha um ícone. Ao final, clique em “Add Widget” e estará disponível no dashboard, tal como mostra a imagem a seguir.
 
Quando o ESP-01s estiver conectado à rede e à internet (evento que poderá ser acompanhado através do monitor serial), aquela área amarelada com a palavra “offline” ao centro será retirada. Um teste rápido com o mouse pode ser feito. Ao clicar, o LED embarcado acenderá. Ao evento de um novo clique, o LED se apagará. Para conferir se o mesmo ocorre em redes diferentes, convido à conexão de um dispositivo móvel por rede móvel e faça o login conforme no início deste documento. A página com o dashboard será carregada. O evento clique será capaz de alterar o estado do LED com sucesso.

O APLICATIVO
Apesar de informar na página myDevices e Cayenne sobre sua disponibilidade no Play Store (não foi testado sua disponibilidade na Apple Store), o app não foi encontrado. E é facilmente confundido seu nome com o de automóveis da Porsche. O que me forçou a buscar pelo apk em fontes externas e fui bem sucedido.
O link externo: https://apkpure.com/cayenne/com.mydevices.cayenne/download?from=details
Com a instalação do apk baixado, faz-se o login como na página e o dashboard simplificado, apresentando primariamente o botão criado aparecerá.
Os testes podem ser feitos normalmente em redes distintas e em todas as oportunidades obterá sucesso.
Visite: www.lojamekanus.com.br e acompanhe as ofertas e novidades.
