platform :ios, '12.0'
use_frameworks!

# def append_header_search_path(target, path)
#     target.build_configurations.each do |config|
#         # Note that there's a space character after `$(inherited)`.
#         config.build_settings["HEADER_SEARCH_PATHS"] ||= "$(inherited) "
#         config.build_settings["HEADER_SEARCH_PATHS"] << path
#     end
# end

target 'sprawl_opengl' do
  pod 'glm'
end

target 'sprawl_metal' do
  pod 'glm'
end

# post_install do |installer|
#     installer.pods_project.targets.each do |target|
#       if target.name == "sprawl_metal"
#           append_header_search_path(target, "$(PROJECT_DIR)/libraries/metal-cpp")
#       end
#     end
#   end
