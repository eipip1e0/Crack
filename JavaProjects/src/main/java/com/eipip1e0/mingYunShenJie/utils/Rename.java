package com.eipip1e0.mingYunShenJie.utils;

import com.eipip1e0.mingYunShenJie.DAO.AssetsDAO;
import com.eipip1e0.mingYunShenJie.DAO.impl.AssetsDAOImpl;

import java.io.File;
import java.util.List;
import java.util.Map;

/**
 * 通过读取sqlite中的数据，将文件从一个地方移动到另一个地方并且重命名。
 *
 *
 */
public class Rename {
    AssetsDAO assetsDAO = new AssetsDAOImpl();
    public void rename(String inputFolder,String outputFolder){
        //检查文件格式
        if(inputFolder.charAt(inputFolder.length()-1) != '/'){
            inputFolder += '/';
        }
        if(outputFolder == null){
            String parent = new File(inputFolder).getParent();
            outputFolder = parent + "\\output\\";
        }

        //1. 创建文件夹

        createFolder(outputFolder);
        //2. 移动并且重命名
        moveAndRename(inputFolder,outputFolder);
        System.out.println("finished");

    }

    private void createFolder(String outputFolder) {
        //1. 遍历sqlite
        List<String> logicAddresses = assetsDAO.queryLogicAddress();
        //2. 依次创建file对象
        for(String eachLogicAddress : logicAddresses) {
            File eachFile = new File(outputFolder + eachLogicAddress);
            File parentFile = eachFile.getParentFile();
            if(!parentFile.exists()){
                if(parentFile.mkdirs() == false){
                    throw new RuntimeException(parentFile.getName()+"：目录创建失败");
                }
            }
            //3. 创建文件夹。
        }
    }
    private void moveAndRename(String inputFolder, String outputFolder) {
        //1. 遍历sqlite
        Map<String, String> logicAndRealForMap = assetsDAO.queryLogicAndRealForMap();
        //2. 依次创建 源 目 地址的file对象
        logicAndRealForMap.forEach((logic,real)->{
            File logicFile = new File(outputFolder+logic);
            File realFile = new File(inputFolder+real);
            if(realFile.exists()){
                boolean b = realFile.renameTo(logicFile);
                if(b == false){
                    throw new RuntimeException("移动并重命名失败");
                }
            }

        });
        //3. 重命名并移动

    }



}
