#include "iostream"
#include "map"
#include "boost/foreach.hpp"

//map的自动去重 及 自动排序
void map_Sample()
{
  std::map<int, int> Vmap;
  //初始化
  Vmap[9] = 9;
  Vmap[8] = 8;
  Vmap[7] = 7;
  Vmap.insert(std::pair<int, int>(4, 1));
  Vmap.insert(std::pair<int, int>(4, 4));
  Vmap.insert(std::pair<int, int>(3, 4));
  Vmap.insert(std::pair<int, int>(1, 2));

  //遍历
  std::map<int, int>::iterator mapIter=Vmap.begin();
  for(; mapIter != Vmap.end(); ++mapIter)
  {
    std::cout << "map element: " << mapIter->first << " ==> " << mapIter->second << std::endl;
  }
}

//map遍历
void map_Traversal()
{
  std::map<int, std::string> useMap;
	for(int i = 5; i <= 10; ++i)
	{
		useMap.insert(std::pair<int, std::string>(i, "hello"));
	}
	//insert
	useMap.insert(std::map<int, std::string>::value_type(0, "zero"));

  //普通遍历方法
	std::map<int, std::string>::iterator useMap_iter = useMap.begin();
	for(; useMap.end() != useMap_iter; ++useMap_iter)
	{
		std::cout << useMap_iter->first << " ==> " << useMap_iter->second <<std::endl;
	}
  std::cout << "----------" << std::endl;
  //BOOST_FOREACH遍历
  typedef std::pair<int, std::string> const_map;
	if(!useMap.empty())
	{
		BOOST_FOREACH(const_map value_map, useMap)
		{
			std::cout << value_map.first << " ==> " << value_map.second << std::endl;
		}
	}

}

void map_Element()
{
  std::map<int, std::string> useMap;
	for(int i = 5; i <= 10; ++i)
	{
		useMap.insert(std::pair<int, std::string>(i, "hello"));
	}
	//insert
	useMap.insert(std::map<int, std::string>::value_type(0, "zero"));

  std::cout << "first element: " << useMap.begin()->first << " ==> " << useMap.begin()->second << std::endl;
	std::cout << "last element: " << (--useMap.end())->first << " ==> " << (--useMap.end())->second << std::endl;
	//error: SIGSEGV - map.end()是一个未知地址
	// std::cout << "map.end() element: " << useMap.end()->first << std::endl;
	// std::cout << useMap.end()->second << std::endl;

  std::map<int, std::string>::iterator useMap_iter = useMap.find(10);
	std::cout << "the 10th element: " << useMap_iter->first << " ==> " << useMap_iter->second << std::endl;

  std::cout << "map size: " << useMap.size() << std::endl;
	//erase
	useMap.erase(useMap_iter);
	std::cout << "map size: " << useMap.size() << std::endl;
}

void map_ElementAdditional()
{
	std::map<char, int> endMap;
	endMap['a'] = 100;
	endMap['b'] = 200;
	endMap['c'] = 300;
	std::map<char, int>::iterator iter = endMap.end();
  //(*iter).first 为 NULL
	std::cout << "endMap.end(): " << (*iter).first << " ==> " << (*iter).second << std::endl;
  //endMap.end() 是一个未知地址，且 iterator 没有重载<<
	// std::cout << "endMap.end() address: " << iter << std::endl;

	iter = endMap.begin();
	//std::cout << "endMap.begin() address: " << iter << std::endl;

	iter = endMap.find('b');
	if (endMap.end() != iter)
	{
		std::cout << "endMap['b']: " << (*iter).first << " => " << (*iter).second << std::endl;
		//std::cout << "endMap.['b'] address: " << iter << std::endl;
	}
}

int main()
{
  map_Sample();
  std::cout << "----------" << std::endl;
  map_Traversal();
  std::cout << "----------" << std::endl;
  map_Element();
  std::cout << "----------" << std::endl;
  map_ElementAdditional();

  return 0;
}
