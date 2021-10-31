package com.eipip1e0.mingYunShenJie.DAO;

import java.util.List;
import java.util.Map;

public interface AssetsDAO {
    List<String> queryLogicAddress();
    List<String> queryRealAddress();
    Map<String,String> queryLogicAndRealForMap();
}
