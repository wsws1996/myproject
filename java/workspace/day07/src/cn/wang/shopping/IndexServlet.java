package cn.wang.shopping;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class IndexServlet extends HttpServlet {

	/**
	 * Destruction of the servlet. <br>
	 */
	public void destroy() {
		super.destroy(); // Just puts "destroy" string in log
		// Put your code here
	}

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.getSession();
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter printWriter = response.getWriter();
		printWriter.write("本网站有如下书:<br/>");
		Set<Map.Entry<String, Book>> set = DB.getAll().entrySet();
		for (Map.Entry<String, Book> me : set) {
			Book book = me.getValue();
			String url = "/day07/servlet/BuyServlet?id=" + book.getId();
			url = response.encodeURL(url);
			printWriter.write(book.getName() + "   <a href='" + url
					+ "'>购买</a><br/>");
		}
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		doGet(request, response);
	}

	/**
	 * Initialization of the servlet. <br>
	 * 
	 * @throws ServletException
	 *             if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
	}

}

class DB {
	static private Map<String, Book> map = new LinkedHashMap<String, Book>();
	static {
		map.put("1", new Book("1", "javaweb开发", "老张", "一本好书"));
		map.put("2", new Book("2", "spring开发", "老黎", "一本好书"));
		map.put("3", new Book("3", "hibernate开发", "老董", "一本好书"));
		map.put("4", new Book("4", "struts开发", "老毕", "一本好书"));
		map.put("5", new Book("5", "ajax开发", "老张", "一本好书"));
	}

	public static Map<String, Book> getAll() {
		return map;
	}
}

class Book {

	public Book() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Book(String id, String name, String author, String description) {
		super();
		this.id = id;
		this.name = name;
		this.author = author;
		this.description = description;
	}

	private String id;
	private String name;
	private String author;
	private String description;

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}
}
