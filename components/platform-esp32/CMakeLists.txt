set(SRC "main.c"
        "dhtsensor/dhtplatform.c"
        "dhtsensor/dhtsensor.c"
        "serialpublisher/serialpublisher.c"
        "os/os.c")

set (INC "."
         "dhtsensor"
         "serialpublisher"
         "os")

idf_component_register(SRCS ${SRC}
                       INCLUDE_DIRS ${INC}
                       REQUIRES driver esp_timer)

# Link pure CMake components
target_link_libraries(${COMPONENT_LIB} PRIVATE CondensationMonitorApp)
target_link_libraries(${COMPONENT_LIB} PRIVATE DHT)
