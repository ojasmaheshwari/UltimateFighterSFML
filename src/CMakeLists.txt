
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})
target_link_libraries(
		${PROJECT_NAME}
		PUBLIC
    ImGui-SFML::ImGui-SFML
		# Have to link sfml-audio explicitly again because
		# for some reason audio linking fails
		# TODO: Fix this as windows users will have a pain in the ass with this
		sfml-audio
)

include(Install.cmake)
