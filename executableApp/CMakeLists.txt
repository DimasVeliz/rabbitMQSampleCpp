add_executable(pervasive-exec-rabbitmq main.cpp)

target_link_libraries(pervasive-exec-rabbitmq PRIVATE amqpManager)