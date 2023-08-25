/*
    Esse programa realiza o print de mensagens no terminal e também
    cria tópicos para poder enviar as mensagens

*/

#include <string>
#include "ros/ros.h" //Necessário sempre para criar nó no ROS
#include "std_msgs/String.h" // Necessário para trabalhar com mensagens

int main(int argc, char **argv){
    
    ros::init(argc, argv, "talker_cpp"); // criação do nó
    ros::NodeHandle nh; // lida com a comunicação do nó

    ros::Rate loop_rate(10); // a 1 iteração a cada 10hz

                                                          //(topic_name, buffer)
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter",   10000); // criação do publisher
    
    int count  = 0;
    
    while(ros::ok()){
        std::string txt = "Ola ROS! Contagem: " + std::to_string(count++);
        
        //Recurso do ROS para debugging (ROS_WARN, ROS_ERRO, ...)
        ROS_INFO("%s", txt.c_str());
        
        std_msgs::String msg;
        msg.data = txt;
        
        // publica a mensagem
        chatter_pub.publish(msg);

        // Atualiza para o nó todas as informações e serviços para o nó
        ros::spinOnce();
        // dorme pelo período equivalente a frequência
        loop_rate.sleep();
    }
    
    return 0;
}