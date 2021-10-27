package com.eipip1e0.mingYunShenJie;

import com.eipip1e0.mingYunShenJie.utils.Rename;

public class Main {
    public static void main(String[] args) {
        Rename rename = new Rename();
        //注释，java中\\=\ , / = / ,两者均可用。
        String inputFolder = "E:\\Documents\\拆包\\命运神界\\main.40.com.superprism.illusion";
        String outputFolder = null;
        rename.rename(inputFolder, outputFolder);
    }
}
