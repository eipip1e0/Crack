package com.eipip1e0.mingYunShenJie;

import com.eipip1e0.mingYunShenJie.bean.PathManager;
import com.eipip1e0.mingYunShenJie.utils.Rename;

public class Main {
    /**
     * @param args: args[0] 用于指定待处理文件路径
     *            args[1] 用于指定assets.db路径
     *
     */
    public static void main(String[] args) {
        Rename rename = new Rename();
        String inputFolder = args[0];
        String outputFolder = null;
        PathManager pathManager = PathManager.getInstance();
        pathManager.setDbPath(args[1]);

        rename.rename(inputFolder, outputFolder);
    }
}
