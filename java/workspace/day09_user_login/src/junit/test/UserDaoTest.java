package junit.test;

import java.util.Date;

import org.junit.Test;

import cn.wang.dao.impl.UserDaoXmlImpl;
import cn.wang.domain.User;

public class UserDaoTest {
	@Test
	public void testAdd() {
		User user=new User();
		user.setId("22222");
		user.setUsername("bbbb");
		user.setPassword("123");
		user.setEmail("bb@sina.com");
		user.setBirthday(new Date());
		UserDaoXmlImpl dao= new UserDaoXmlImpl();
		dao.add(user);
	}
	@Test
	public void testFind()
	{
		UserDaoXmlImpl dao=new UserDaoXmlImpl();
		User user= dao.find("bbbb", "123");
		System.out.println(user.getId());
	}
}
