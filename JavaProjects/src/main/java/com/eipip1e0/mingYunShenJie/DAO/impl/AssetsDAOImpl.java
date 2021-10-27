package com.eipip1e0.mingYunShenJie.DAO.impl;

import com.eipip1e0.mingYunShenJie.DAO.AssetsDAO;
import com.eipip1e0.mingYunShenJie.bean.PathManager;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AssetsDAOImpl implements AssetsDAO {
    @Override
    public List<String> queryLogicAddress() {
        String dbPath = PathManager.getInstance().getDbPath();
        if(dbPath == null){
            throw new RuntimeException("未指定正确的assets.db路径");
        }
        String url = "jdbc:sqlite:"+dbPath;
        Connection connection = null;
        List<String> logicAddresses = null;
        try {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection(url);
            String sql = "select `logic` from `assets`";
            PreparedStatement preparedStatement = connection.prepareStatement(sql);
            ResultSet resultSet = preparedStatement.executeQuery();
            ResultSetMetaData metaData = resultSet.getMetaData();
            logicAddresses = new ArrayList<>();
            while(resultSet.next()){
                    logicAddresses.add((String) resultSet.getObject(1));
            }
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            if(connection!=null){
                try {
                    connection.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }

        }

        return logicAddresses;

    }

    @Override
    public List<String> queryRealAddress() {
        String dbPath = PathManager.getInstance().getDbPath();
        if(dbPath == null){
            throw new RuntimeException("未指定正确的assets.db路径");
        }

        String url = "jdbc:sqlite:"+dbPath;
        Connection connection = null;
        List<String> realAddresses = null;
        try {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection(url);
            String sql = "select `real` from `assets``";
            PreparedStatement preparedStatement = connection.prepareStatement(sql);
            ResultSet resultSet = preparedStatement.executeQuery();
            ResultSetMetaData metaData = resultSet.getMetaData();
            realAddresses = new ArrayList<>();
            while(resultSet.next()){
                realAddresses.add((String) resultSet.getObject(1));
            }
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            if(connection!=null){
                try {
                    connection.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }

        }

        return realAddresses;
    }

    @Override
    public Map<String, String> queryLogicAndRealForMap() {
        String dbPath = PathManager.getInstance().getDbPath();
        if(dbPath == null){
            throw new RuntimeException("未指定正确的assets.db路径");
        }
        String url = "jdbc:sqlite:"+dbPath;
        Connection connection = null;
        Map<String,String> logicAndRealAddressesMap = null;
        try {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection(url);
            String sql = "select `real`,`logic` from `assets`";
            PreparedStatement preparedStatement = connection.prepareStatement(sql);
            ResultSet resultSet = preparedStatement.executeQuery();
            ResultSetMetaData metaData = resultSet.getMetaData();
            logicAndRealAddressesMap = new HashMap<>();
            while(resultSet.next()){
                String value = (String) resultSet.getObject(1);
                String key = (String) resultSet.getObject(2);
                logicAndRealAddressesMap.put(key,value);
            }
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            if(connection!=null){
                try {
                    connection.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }

        }

        return logicAndRealAddressesMap;
    }
}
