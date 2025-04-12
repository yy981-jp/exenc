#include <iostream>
#include <string>
#include <filesystem>
#include <yy981/return.h>
#include <yy981/string.h>

namespace fs = std::filesystem;


int main(int argc, char* argv[]) {
	if (argc < 3) return_u("venc <対象Dir> <CMD> [CMD] ...\nCMDはスペースを入れてから全て結合され、一つのコマンドとみなします");
	if (!fs::exists(argv[1])) throw std::runtime_error("対象Dirが存在しません");
	std::string CMD;
	for (int i = 2; i < argc; ++i) {
		if (i > 2) CMD += " ";
		CMD += argv[i];
	}
	for (const fs::directory_entry& x: fs::recursive_directory_iterator(argv[1])) {
		if (x.path().extension() == ".mp4" && x.path().stem().extension() != "enc") {
			std::string tCMD = CMD;
			st::replace_r(tCMD,"IFILE","\""+x.path().string()+"\"");
			st::replace_r(tCMD,"IDIR",x.path().parent_path().string());
			st::replace_r(tCMD,"INAME",x.path().stem().string());
			std::system(tCMD.c_str());
		}
	}
}