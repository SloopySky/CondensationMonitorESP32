idf_component_register(SRCS "main.c" "dhtsensor/dhtplatform.c" "dhtsensor/dhtsensor.c" "serialpublisher/serialpublisher.c" "os/os.c"
                       INCLUDE_DIRS "." "dhtsensor" "serialpublisher" "os"
                       REQUIRES driver esp_timer)

# Link pure CMake components
target_link_libraries(${COMPONENT_LIB} PRIVATE CondensationMonitorApp)
target_link_libraries(${COMPONENT_LIB} PRIVATE DHT)
