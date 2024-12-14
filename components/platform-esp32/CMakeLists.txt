idf_component_register(SRCS "main.c" "dhtsensor/dhtplatform.c"
                       INCLUDE_DIRS "." "dhtsensor"
                       REQUIRES driver esp_timer)

# Link pure CMake components
target_link_libraries(${COMPONENT_LIB} PRIVATE CondensationMonitorApp)
target_link_libraries(${COMPONENT_LIB} PRIVATE DHT)
