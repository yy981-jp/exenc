#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;


inline void cmd(const std::string cmd) {
    if (std::system(cmd.c_str())) throw std::runtime_error("cmd(): " + cmd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "venc_h265v <対象Dir> <拡張子>";
        return 0;
    }

    for (auto e: fs::recursive_directory_iterator(argv[1])) {
        fs::path inpFile = e.path();
        if (
            inpFile.extension().string() != std::string(argv[2])
            || inpFile.string().ends_with(".h265.mp4")
        ) continue;
 
    	std::string temp_file_name = std::to_string(static_cast<int64_t>(std::time(nullptr)));
        std::string tempInpFile = temp_file_name + inpFile.extension().string();
        std::string tempOutFile = temp_file_name + ".h265.mp4";
        fs::rename(inpFile, tempInpFile);

        fs::path outFile = inpFile.parent_path() / fs::path(inpFile.stem().string() + ".h265.mp4");
        std::string cmdStr = "ffmpeg -y -loglevel error -i \"" + tempInpFile + "\" -preset veryslow -c:v hevc_qsv \"" + tempOutFile + "\"";
        std::cout << "[" << inpFile.string() << "]: " << cmdStr << "\n";

        try {
            cmd(cmdStr);
        } catch (const std::runtime_error& err) {
            fs::rename(tempInpFile, inpFile);
            fs::remove(tempOutFile);
            throw err;
        }

        fs::rename(tempOutFile, outFile);
        fs::remove(tempInpFile);
    }
}