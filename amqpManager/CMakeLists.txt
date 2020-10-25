set(GCC_COVERAGE_COMPILE_FLAGS "-fPIC")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})


add_library(
    amqpManager SHARED
    src/amqpManager/pervasiveObj.hpp
    src/amqpManager/pervasiveObj.cpp
    src/amqpManager/Weirdo.hpp
    src/amqpManager/Weirdo.cpp
    src/amqpManager/amqpMNGR.hpp
    src/amqpManager/amqpMNGR.cpp
)
target_include_directories(amqpManager PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src") 
target_link_libraries(amqpManager amqpGhFixed)



