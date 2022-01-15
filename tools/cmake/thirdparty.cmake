set(EXTERNAL_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

option (USE_EXTERNAL "" ON)

if(USE_EXTERNAL)

    message(STATUS "Use thirdparty libs.")

    function(include_glfw GLFW_LIB)
        set(GLFW_PATH ${EXTERNAL_FOLDER}/glfw)
        target_include_directories(radye_engine PUBLIC ${GLFW_PATH}/include)
        target_link_directories(radye_engine PUBLIC ${GLFW_PATH}/${GLFW_LIB})
        target_link_libraries(radye_engine PUBLIC glfw3)
    endfunction(include_glfw)

    function(include_glm)
        set(GLM_PATH ${EXTERNAL_FOLDER}/glm)
        target_include_directories(radye_engine PUBLIC ${GLM_PATH})
    endfunction(include_glm)

    function(include_vulkan_sdk)
        set(VULKAN_SDK_PATH ${EXTERNAL_FOLDER}/vulkan_sdk)
        target_include_directories(radye_engine PUBLIC ${VULKAN_SDK_PATH}/Include)
        target_link_directories(radye_engine PUBLIC ${VULKAN_SDK_PATH}/Lib)
        target_link_libraries(radye_engine PUBLIC vulkan-1)
    endfunction(include_vulkan_sdk)

    function(include_imgui)
        set(IMGUI_PATH ${EXTERNAL_FOLDER}/imgui)
        target_include_directories(radye_engine PUBLIC ${IMGUI_PATH})
    endfunction(include_imgui)

    function(include_sdl2)
        set(SDL2_PATH ${EXTERNAL_FOLDER}/SDL2)
        target_include_directories(radye_engine PUBLIC ${SDL2_PATH}/include)
        target_link_directories(radye_engine PUBLIC ${SDL2_PATH}/lib)
    endfunction(include_sdl2)

else(!USE_EXTERNAL)

    message(WARNING "Don't use external libs.")

endif(USE_EXTERNAL)
