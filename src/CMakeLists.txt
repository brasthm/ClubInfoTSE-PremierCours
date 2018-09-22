add_executable(${PROJECT_NAME} 
        AnimatedSprite.h
        AnimatedSprite.cpp
        background.h
        background.cpp
        constantes.h
        DJ.h
        DJ.cpp
        entite.h
        entite.cpp
        initSprite.h
        initSprite.cpp
        main.cpp
        Obstacle.h
        Player.h
        Player.cpp
    )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)


find_package(SFML 2 COMPONENTS audio graphics window system REQUIRED)
if(SFML_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()