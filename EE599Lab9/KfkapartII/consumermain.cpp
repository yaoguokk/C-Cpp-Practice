#include "KafkaConsumer.h"

 
static void msg_consume(rd_kafka_message_t *rkmessage, void *opaque)
{
	printf("[MSG] %d: %s\n", (int)rkmessage->len, (char *)rkmessage->payload);
}
 
 
int main(int argc, char *argv[])
{
	CKafkaConsumer kc;
 
	char topic[] = "test";
	char brokers[] = "192.168.2.73:9092";
	char partitions[] = "0";
	char groupId[] = "my_group1";
	consumer_callback consumer_cb = msg_consume; //注册消息回调函数，用户可以自定义此函数
	void * param_cb = NULL; //param_cb=this;
	int ret = 0;
 
	ret = kc.init(topic, brokers, partitions, groupId, consumer_cb, param_cb);
	if(ret != 0){printf("Error: kc.init(): ret=%d;\n", ret); return 0;}
 
	ret = kc.getMessage(); //从kafka服务器接收消息
	if(ret != 0){printf("Error: kc.getMessage(): ret=%d;\n", ret); return 0;}
 

    return 0;
}