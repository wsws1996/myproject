package cn.wang.service;

import java.util.Map;

import cn.wang.dao.BookDao;

public class BusinessService {
	BookDao dao = new BookDao();

	public Map getAllBook() {
		return dao.getAll();
	}
	
}
