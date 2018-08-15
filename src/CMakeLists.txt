add_executable(${PROJECT_NAME} 
        constantes.h
        entite.h
        entite.cpp
        main.cpp
        spriteAnimer.h
        spriteAnimer.cpp
    )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)


find_package(SFML 2 COMPONENTS audio graphics window system REQUIRED)
if(SFML_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()