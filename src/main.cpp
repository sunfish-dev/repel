#include <iostream>
#include <vector>
#include "io.hpp"
#include "file.hpp"

#define PATH_EXIST_ERROR(path) if (!fs::exists(path)) Crash(1, "path: ", path.string(), " does not exist\n")
#define EMPTY_ARG_ERROR(arg) if (std::string_view(arg).empty()) Crash(1, "argument cannot be empty\n")
#define TOO_FEW_ARGS_ERROR(expect, provided) if (provided < expect) Crash(1, "too few arguments provided\n")
#define TOO_MANY_ARGS_ERROR(expect, provided) if (provided > expect) Crash(1, "too many arguments provided\n")
#define EXPECT_ARGS_ERROR(expect, provided) TOO_FEW_ARGS_ERROR(expect, provided); TOO_MANY_ARGS_ERROR(expect, provided)

#define REPEL_VERSION "0.1"

std::vector<fs::path> GetAllFiles(const fs::path& path)
{
    std::vector<fs::path> files;

    for (const auto& entry : fs::directory_iterator(path))
    {
        if (fs::is_regular_file(entry))
        {
            files.push_back(entry);   
        }
        else if (fs::is_directory(entry))
        {
            auto newFiles = GetAllFiles(entry);
            files.insert(files.end(), newFiles.begin(), newFiles.end());
        }
    }

    return files;
}

std::string StringReplace(const std::string& str, const std::string& find, const std::string& replace)
{
    std::string newStr;

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str.substr(i, (int)find.length()) == find)
        {
            newStr+=replace;
            i+=(int)find.length()-1;
        }
        else newStr+=str[i];
    }

    return newStr;
}

int main(int argc, char** argv)
{
    if (argc == 1) Crash(1, "No command provided. Use repel help to view a list of commands\n");

    for (int i = 1; i < argc; i++)
    {
        std::string_view arg = argv[i];

        if (arg == "replace" || arg == "r")
        {
            EXPECT_ARGS_ERROR(3, argc-i-1);

            fs::path path = argv[i+1];

            EMPTY_ARG_ERROR(argv[i+2]);
            EMPTY_ARG_ERROR(argv[i+3]);

            if (fs::is_regular_file(path))
            {
                WriteFile(path, StringReplace(ReadFile(path), argv[i+2], argv[i+3]));
            }
            else if (fs::is_directory(path))
            {
                auto files = GetAllFiles(path);
                
                for (auto file : files)
                    WriteFile(file, StringReplace(ReadFile(file), argv[i+2], argv[i+3]));
            }
            else PATH_EXIST_ERROR(path);

            break;
        }
        else if (arg == "erase" || arg == "e")
        {
            EXPECT_ARGS_ERROR(2, argc-i-1);

            fs::path path = argv[i+1];

            EMPTY_ARG_ERROR(argv[i+2]);

            if (fs::is_regular_file(path))
            {
                WriteFile(path, StringReplace(ReadFile(path), argv[i+2], ""));
            }
            else if (fs::is_directory(path))
            {
                auto files = GetAllFiles(path);
                
                for (auto file : files)
                    WriteFile(file, StringReplace(ReadFile(file), argv[i+2], ""));
            }
            else PATH_EXIST_ERROR(path);

            break;
        }
        else if (arg == "help" || arg == "h")
        {
            TOO_MANY_ARGS_ERROR(0, argc-i-1);

            PrintLines(
                "replace <PATH> <FIND> <REPLACE> - replaces all instances of a string in a file or directory with a new string",
                "erase <PATH> <FIND> - erases all instances of a string in a file or directory",
                "help - prints this message",
                "version - prints the repel version"
            );
        }
        else if (arg == "version" || arg == "v")
        {
            TOO_MANY_ARGS_ERROR(0, argc-i-1);

            PrintLine("Repel Version ", REPEL_VERSION);
        }
        else Crash(1, "command: ", arg, " not found\n");
    }
}