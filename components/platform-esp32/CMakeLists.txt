idf_component_register(SRCS "main.c"
                       INCLUDE_DIRS ".")

# Link pure CMake components
target_link_libraries(${COMPONENT_LIB} PRIVATE CondensationMonitorApp)
target_link_libraries(${COMPONENT_LIB} PRIVATE DHT)
