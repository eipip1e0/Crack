package com.eipip1e0.mingYunShenJie.bean;

public class PathManager {
    private String inputPath;
    private String dbPath;
    private static PathManager path = null;

    private PathManager(){}

    public String getInputPath() {
        return inputPath;
    }

    public void setInputPath(String inputPath) {
        this.inputPath = inputPath;
    }

    public String getDbPath() {
        return dbPath;
    }

    public void setDbPath(String dbPath) {
        this.dbPath = dbPath;
    }

    public static PathManager getInstance(){
        if(path == null){
            path = new PathManager();
        }
        return path;
    }
}
