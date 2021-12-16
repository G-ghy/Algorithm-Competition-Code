import os
import os.path


def clearFilesInDictionary(dictionaryPath):
    files = os.listdir(dictionaryPath)
    for file in files:
        filePath = dictionaryPath + "\\" + file
        if os.path.isdir(filePath):
            clearFilesInDictionary(filePath)
        else:
            pass
            fileSuffix = os.path.splitext(filePath)[1]
            if fileSuffix == '.exe':
                os.remove(filePath)

if __name__ == "__main__":
    basePath = os.getcwd()
    dictionaryNames = ["leetcode", "acwing", "codeForces", "牛客", "pta", "atcoder", "对拍"]

    for dictionaryName in dictionaryNames:
        dictionaryPath = basePath + "\\" + dictionaryName
        clearFilesInDictionary(dictionaryPath)