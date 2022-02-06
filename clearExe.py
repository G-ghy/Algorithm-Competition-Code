import os
import os.path


def clearFilesInDictionary(dictionaryPath):
    files = os.listdir(dictionaryPath)
    for file in files:
        filePath = dictionaryPath + "\\" + file
        if os.path.isdir(filePath):
            clearFilesInDictionary(filePath)
        else:
            fileInfo = os.path.split(filePath)[1] # os.path.split(filePath) 获取(文件路径，文件名称.文件后缀)的元组
            fileInfoDetail = fileInfo.split('.')

            fileName = fileInfoDetail[0]
            fileSuffix = ""
            if len(fileInfoDetail) > 1 :
                fileSuffix = fileInfoDetail[1]

            # fileSuffix = os.path.splitext(filePath)[1] # 获取文件后缀
            if fileName == 'tempCodeRunnerFile' or fileSuffix == 'exe':
                print("删除文件: " + filePath)
                os.remove(filePath)
if __name__ == "__main__":
    basePath = os.getcwd()
    clearFilesInDictionary(basePath);