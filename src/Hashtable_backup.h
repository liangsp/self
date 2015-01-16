/*!
* @file Hashtable.h
* @brief 哈希表类
*
* 对哈希表的一些基本操作的封装
*
* @version 1.0
* @date 2012-11-25
* @bug
*/

#ifndef __HASH_TABLE__
#define __HASH_TABLE__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <assert.h>
#include "self_typdef.h"

#if defined(_MSC_VER)
#pragma warning(disable:4996) //全部关掉
#endif


/* 7.18.1.1  Exact-width integer types */
// typedef signed char           int8_t;
// typedef unsigned char         uint8_t;
// typedef short                 int16_t;
// typedef unsigned short        uint16_t;
// typedef int                   int32_t;
// typedef unsigned              uint32_t;
// typedef long long             int64_t;
// typedef unsigned long long    uint64_t;

//namespace lspublic {
//    namespace library {
//        namespace sdata {
/**
* @brief 哈希表帮助类
* 针对关键字类型为 int32_t
* 示例:
* 	CHashtable<CInt32Helper, Value> table;
*	table.put(2, vaule);
* 	value = table.get(2);
*/
class CInt32Helper
{
public:
	int32_t m_nInt32Value;

public:
	/**
	 * @brief 哈希表帮助类构造函数
	 * @param nValue[in] 关键字初始值
	 * @return void
	 * @retval none
	 */
	CInt32Helper(int32_t nValue = 0):m_nInt32Value(nValue) {};
	/**
	 * @brief 哈希表操作符重载函数
	 * @param none
	 * @return int32_t
	 * @retval 数据成员
	 */
	virtual  operator int32_t()
	{
		return m_nInt32Value;
	}
	/**
	 * @brief 哈希码函数
	 * @param none
	 * @return int32_t
	 * @retval 哈希码
	 */

	int32_t hashCode() const
	{
		return (int32_t)m_nInt32Value;
	}
	/**
	 * @brief 比较两个对象的数据成员
	 *
	 * 比较两个CInt32Helper对象的数据成员m_nInt32Value的值，并返回比较结果
	 *
	 * @param other[in] 进行比较的哈希表帮助类对象的引用
	 * @return bool
	 * @retval true 相等
	 * @retval false 不相等
	 */
	bool equals(const CInt32Helper& other) const
	{
		return m_nInt32Value == other.m_nInt32Value;
	}
};

/**
* @brief 哈希表帮助类
* 针对关键字为 int64_t
* 示例:
* 	CHashtable<CInt64Helper, Value> table;
*	table.put(2, vaule);
* 	value = table.get(2);
*/
class CInt64Helper
{
public:
	int64_t m_lInt64Value;

public:
	/**
	 * @brief 哈希表帮助类构造函数
	 * @param lValue[in] 关键字初始值
	 * @return void
	 * @retval none
	 **/
	CInt64Helper(int64_t lValue = 0):m_lInt64Value(lValue) {};
	/**
	 * @brief 哈希表操作符重载函数
	 * @param none
	 * @return int64_t
	 * @retval 数据成员
	 */
	virtual operator int64_t()
	{
		return m_lInt64Value;
	}
	/**
	 * @brief 哈希码函数
	 * @param none
	 * @return int64_t
	 * @retval 哈希码
	 */
	int64_t hashCode() const
	{
		return (int64_t)m_lInt64Value;
	}
	/**
	 * @brief 比较两个对象的数据成员
	 *
	 * 比较两个CInt64Helper对象的数据成员m_lInt64Value的值，并返回比较结果
	 *
	 * @param other[in] 进行比较的哈希表帮助类对象的引用
	 * @return bool
	 * @retval true 相等
	 * @retval false 不相等
	 */
	bool equals(const CInt64Helper& other) const
	{
		return m_lInt64Value == other.m_lInt64Value;
	}
};

/**
* @brief 哈希表帮助类
* 针对关键字类型为 long
* 示例:
* 	CHashtable<CInteger, Value> table;
*	table.put(2, vaule);
* 	value = table.get(2);
*/
class CIntegerHelper
{
public:
	long m_nValue;

public:
	/**
	 * @brief 哈希表帮助类构造函数
	 * @param nValue[in] 关键字初始值
	 * @return void
	 * @retval none
	 */
	CIntegerHelper(long nValue = 0):m_nValue(nValue) {};
	/**
	 * @brief 哈希表操作符重载函数
	 * @param none
	 * @return long
	 * @retval 数据成员
	 */
	virtual operator long()
	{
		return m_nValue;
	}
	/**
	 * @brief 哈希码函数
	 * @param none
	 * @return unsigned int
	 * @retval 哈希码
	 */
	unsigned int hashCode() const
	{
		return (unsigned int)m_nValue;
	}
	/**
	 * @brief 比较两个对象的数据成员
	 *
	 * 比较两个CInt64Helper对象的数据成员m_nValue的值，并返回比较结果
	 *
	 * @param other[in] 进行比较的哈希表帮助类对象的引用
	 * @return bool
	 * @retval true 相等
	 * @retval false 不相等
	 */
	bool equals(const CIntegerHelper& other) const
	{
		return m_nValue == other.m_nValue;
	}
	/**
	 * @brief 操作符重载
	 *
	 * 复制另一个CIntegerHelper对象的数据成员m_nValue的值，并返回调用对象
	 *
	 * @param other[in] 进行复制的源CIntegerHelper类对象的引用，右值
	 * @return CIntegerHelper&
	 * @retval 调用的对象
	 */
	//added by xxm 2009-06-27
	CIntegerHelper& operator =(const CIntegerHelper& other)
	{
		m_nValue = other.m_nValue;
		return *this;
	}
	/**
	 * @brief 取数据成员
	 *
	 * 取得CIntegerHelper对象的数据成员m_nValue的值，并返回
	 *
	 * @param none
	 * @return long
	 * @retval 数据成员
	 */
	//added by xxm 2009-06-27
	long GetValue() const
	{
	     return m_nValue;
	}
};

/**
* @brief 哈希表帮助类 (模板)
* 针对关键字类型为 Type
* 示例:
* 	CHashtable<Type> table;
*	table.put(number, vaule);
* 	value = table.get(number);
*/

template <class Type>
class CNumberHelper
{
	Type m_value;

public:
	/**
	 * @brief 哈希表帮助类构造函数
	 * @param value[in] 关键字初始值
	 * @return void
	 * @retval none
	 */
	CNumberHelper(Type value = 0):m_value(value) {};
	/**
	 * @brief 取数据成员
	 *
	 * 取得CNumberHelper对象的数据成员m_value的值，并返回
	 *
	 * @param none
	 * @return Type
	 * @retval 数据成员
	 */
	Type getValue()
	{
		return m_value;
	}
	/**
	 * @brief 取数据成员
	 *
	 * 取得CNumberHelper对象的数据成员m_value的值，并返回
	 *
	 * @param none
	 * @return Type
	 * @retval 数据成员
	 */
	Type getConstValue() const
	{
		return m_value;
	}
	/**
	 * @brief 哈希表操作符重载函数
	 * @param none
	 * @return Type
	 * @retval 数据成员
	 */
	virtual operator Type()
	{
		return m_value;
	}
	/**
	 * @brief 哈希码函数
	 * @param none
	 * @return unsigned int
	 * @retval 哈希码
	 */
	unsigned int hashCode() const
	{
		return (unsigned int)m_value;
	}
	/**
	 * @brief 比较两个对象的数据成员
	 *
	 * 比较两个CInt64Helper对象的数据成员m_nValue的值，并返回比较结果
	 *
	 * @param other[in] 进行比较的哈希表帮助类对象的引用
	 * @return bool
	 * @retval true 相等
	 * @retval false 不相等
	 */
	bool equals(const CNumberHelper& other) const
	{
		return m_value == other.m_value;
	}
};
/**
* @brief 哈希表帮助类
* 针对关键字类型为 String
* 示例:
* 	CHashtable<CStringHelper, Value> table;
*	table.put("apple", vaule);
* 	value = table.get("apple");
*/
class CStringHelper
{
public:
	char* m_szValue;
public:
	/**
	 * @brief 构造函数
	 * @param szValue[in] 初始空字符串的指针，不能为空指针
	 * @return char*
	 * @retval 指向空串的指针
	 */
	CStringHelper(const char* szValue = "")
	{
		assert(NULL != szValue);
		m_szValue = strdup(szValue);
	};
	/**
	 * @brief 虚构函数
	 *
	 * 释放指针
	 *
	 * @param none
	 * @return null
	 * @retval none
	 */
	~CStringHelper()
	{
		free(m_szValue);
	}
	/**
	 * @brief 哈希表操作符重载函数
	 * @param none
	 * @return char *
	 * @retval 数据成员
	 */
	virtual operator const char*() const
	{
		return m_szValue;
	}
	/**
	 * @brief 取数据成员
	 *
	 * 取得CNumberHelper对象的数据成员m_szValue的值，并返回
	 *
	 * @param none
	 * @return char*
	 * @retval 数据成员
	 */
	const char* c_str()
	{
		return m_szValue;
	}
    /**
	 * @brief 计算哈希码
	 *
	 * 取字符串的每个字符，每次将上次取得的哈希值左移三位后加上当前字符的ASCII码，直至取完，返回最后的哈希值
	 *
	 * @param none
	 * @return unsigned int
	 * @retval 哈希码
	 */
	unsigned int hashCode2() const
	{
		unsigned int nHashCode = 0;
		char* ptr = m_szValue;

		while (*ptr)
		{
			nHashCode += (nHashCode << 3) + *ptr;
			++ptr;
		}

		return nHashCode;
	}
	/**
	 * @brief 计算哈希码
	 *
	 * 取字符串的每个字符，每次将上次取得的哈希值左移5位后,减去上次取得的哈希值，再加上当前字符的ASCII码，直至取完，返回最后的哈希值
	 *
	 * @param none
	 * @return unsigned int
	 * @retval 哈希码
	 */
	unsigned int hashCode() const
	{
		unsigned int nHashCode = 0;
		int nLength = strlen(m_szValue);

		for (int i = 0; i < nLength; i++)
		{
			//s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
			//nHashCode = m_szValue[i] + 31*nHashCode;
			nHashCode = m_szValue[i] + ((nHashCode << 5) - nHashCode);
		}

		return nHashCode;
	}
	/**
	 * @brief 比较两个对象的数据成员
	 *
	 * 比较两个CStringHelper对象的数据成员m_szValue的值，并返回比较结果
	 *
	 * @param other[in] 进行比较的类对象的引用
	 * @return bool
	 * @retval true 相等
	 * @retval false 不相等
	 */
	bool equals(const CStringHelper& other) const
	{
		return strcmp(m_szValue, other.m_szValue) == 0;
	}

	/**
	 * @brief 操作符重载
	 *
	 * 复制另一个CIntegerHelper对象的数据成员m_nValue的值，并返回调用对象
	 *
	 * @param other[in] 进行复制的源CIntegerHelper类对象的引用，右值
	 * @return CStringHelper&
	 * @retval 调用的对象
	 */

	CStringHelper& operator=(const CStringHelper& x)
	{
        if(&x != this)
        {
		    free(m_szValue);
		    m_szValue = strdup(x.m_szValue);
        }
		return (*this);
	}
};

/**
* @brief 哈希表
* 该类生成一个哈希表，并将value值映射到对应的哈希码
* 对于任意非空的对象，都可以作为key 或者 value
* 为成功从哈希表中存取对象，作为key值的对象需执行hashCode 和 equals方法
*
*/

template <class Key, class Value>
class CHashtable
{
public:
	CHashtable(unsigned int initialCapacity = 101,
		   float loadFactor = 0.75f, bool bAutoDelete = false);

	virtual ~CHashtable();


    /**
    * @brief返回hash表的大小
	* @return unsigned int
	* @retval 返回hash表的大小
    */
	unsigned int size() const
	{
		return m_nCount;
	}

	/**
    * @brief 测试hash表是否为空
	* @return bool
	* @retval true表示hash表为空，false表示hash非空
    */
	bool isEmpty() const
	{
		return m_nCount == 0;
	}

	/**
     * @brief 测试指定对象是否为key值
	 * @return bool
	 * @retval true表示为key值，false表示非key值
     */
	bool containsKey(const Key& key) const;

	/**
     * @brief 返回指定key对应的value值
     * @param Key&[in] key值
	 * @return Value*
	 * @retval 找到则返回对应的value值，没找到则返回null
     */
	Value* get(const Key& key) const;
	/**
     * @brief 返回指定key对应的value值,操作符重载
     * @param Key&[in] key值
	 * @return Value*
	 * @retval 找到则返回对应的value值，没找到则返回null
     */

	Value* operator[](const Key& key) const;
	/**
     * @brief 将指定的key和指定的value建立映射关系,两者都不能为空
     * @param Key&[in] key值
     * @param Value&[in] Value值
	 * @return void
	 * @retval 该key值在hashtable中之前对应的value值，若没有则返回null
     */
	void  put(const  Key& key, const Value& value);
	/**
     * @brief 扩大hashtable的容量，并重新调整内部结构
     * 当key数超过hashtable容量时，该方法会被自动调用
     *
	 * @return void
	 *
     */
	void  rehash();
	/**
     * @brief 返回hashtable中所有key值
     *
	 * @return Key* hashtable中所有key值
	 *
     */
	const Key* keys();
	/**
     * @brief 返回所有元素值(value值)
     *
	 * @return Value* 所有元素值(value值)
	 *
     */

	const Value* elements();
	/**
     * @brief 移除一个key/value键值对
     * @param Key&[in] 需要移除的key值
	 * @return void
	 * @retval 该key值在hashtable中之前对应的value值，若没有则返回null
     */
	void remove(const Key& key);
	/**
     * @brief 清空hashtable key值
     * @param none
	 * @return void
	 * @retval none
     */
	void  clear();
	/**
     * @brief 清空hashtable value值
     * @param bValue[in] 是否删除value值
	 * @return void
	 * @retval none
     */
	void  clearvalue(bool bValue = false);
    /**
    * @brief 冻结或解冻hash表，冻结后不可以析构
    * @param bFreeze[in]是否冻结
	* @return void
	* @retval none
      */
	void Freeze(bool bFreeze = true);

	/**
	 * @brief 遍历hash表之前的初始化
	 * @param nTravelHead[in] 返回第一个冲突链索引,即0
	 * @param pTravelEntry[in]  返回第一个冲突链的第一个节点，不能为空指针.
     *     如果第一个冲突链为空,则返回NULL
	 * @return  None
	 **/
	void TravelInit(int& nTravelHead, void **pTravelEntry);

	/**
	 * @brief  获取一个hash节点元素
	 * @param  nTravelHead[in]  开始遍历的冲突链索引
	 * @param  pTravelEntry[in] 开始遍历的冲突链节点
	 * @param  key[out] 哈希节点的key值
	 * @return         Value*
     * @retval 如果没有遍历完成,则返回哈希节点所存放的值的指针;遍历完成,返回NULL
	 *                 hash表已经遍历完,则返回1.
	 **/
	Value* GetNextElement(int& nTravelHead, void **pTravelEntry, Key& key);

    /**
    * @brief初始化hash
	* @return void
	* @retval
    */
	void init(unsigned int initialCapacity = 101,
		   float loadFactor = 0.75f, bool bAutoDelete = false);

    void reset(unsigned int initialCapacity = 101,
		   float loadFactor = 0.75f, bool bAutoDelete = false);

private:
	/**
	 * @brief  返回hashtable扩容后的大小
	 * @param  nStart[in] 开始搜索的数值，一般为当前值的两倍
	 * @return unsigned int
     * @retval 大于开始值nStart的最小质数
	 *
	 **/
	unsigned int nextPrime(unsigned int nStart);

private:
	struct HashtableEntry
	{
		unsigned int nHashCode;
		Key key;
		Value value;
		HashtableEntry* next;

		HashtableEntry()
		{
			nHashCode = 0;
			next = NULL;
		}
	};

	HashtableEntry** m_table;

	unsigned int m_nCount;
	unsigned int m_nTableSize;
	unsigned int m_nThreshold;
	float m_fLoadFactor;

	Value valueNull;
	Key* m_keys;
	Value* m_elements;

	bool m_bFreeze;
};

/**
 * @brief Constructs a new, empty hashtable with the
 *              specified initial capacity and the specified
 *              load factor.
 *
 *              A load factor of .75f means that the table will be
 *              expanded when it gets three quarters full. Hashing
 *              works faster when the table is not full. A value
 *              of .25f would use more RAM but would work faster.
 *              A value of 1.0f would use minimal RAM but would run
 *              slowly.
 *
 * @param initialCapacity  the initial capacity of the hashtable.
 * @param loadFactor       the load factor of the hashtable.
 * @return                 None
 */
template <class Key, class Value>
CHashtable<Key,Value>::CHashtable(unsigned int initialCapacity,
                                  float loadFactor,
                                  bool bAutoDelete)
{
	unsigned int i = 0;

	if (loadFactor <= 0.0 || loadFactor >= 1.0)
	{
		//printf( "Bad Argument for loadFactor\n" );
		exit(1);
	}

	m_nCount = 0;
	m_nTableSize = initialCapacity;
	m_fLoadFactor = loadFactor;
	m_nThreshold = (unsigned int)(initialCapacity * loadFactor);

	m_table = new HashtableEntry*[m_nTableSize];
	if (NULL == m_table)
	{
		//printf("memory error! not enough memory or memory limited!");
		exit(-1);
	}

	for( i = 0; i < m_nTableSize; i++ )
	{
		m_table[i] = NULL;
	}

	m_keys = NULL;
	m_elements = NULL;

	m_bFreeze = false;
}

/**
 * @brief Destroy the hashtable
 *
 * @return      None
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
CHashtable<Key,Value>::~CHashtable()
{
	if (m_bFreeze)
	{
		return;
	}

	clear();

	if (m_table)
	{
		delete[] m_table;
		m_table = NULL;
	}

	if (m_keys)
	{
		delete[] m_keys;
		m_keys = NULL;
	}

	if (m_elements)
	{
		delete[] m_elements;
	}

	m_elements = NULL;
}

/**
 * @brief Tests if the specified object is a key
 *              in this hashtable.
 *
 * @param key   possible key.
 * @return      true if and only if the specified object
 *              is a key in this hashtable, as determined
 *              by the equals method; false otherwise.
 * @see         #contains(const Value& value)
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
bool CHashtable<Key,Value>::containsKey(const Key& key) const
{
	if (!m_table)
	{
		return false;
	}

	HashtableEntry** tab = m_table;
	unsigned int nHashCode = 0;

	nHashCode = key.hashCode();

	unsigned int nIndex = nHashCode % m_nTableSize;

	for (HashtableEntry* entry = tab[nIndex]; entry != NULL; entry = entry->next)
	{
		if (entry->nHashCode == nHashCode && entry->key.equals(key))
			return true;
	}

	return false;
}

/**
 * @brief Returns the value to which the specified
 *              key is mapped in this hashtable.
 *
 * @param key   a key in the hashtable.
 * @return      the value to which the key is mapped in this
 *              hashtable; null if the key is not mapped to
 *              any value in this hashtable.
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
Value* CHashtable<Key,Value>::get(const Key& key) const
{
	if ( m_table )
	{
		HashtableEntry** tab = m_table;
		Value* pValue = NULL;
		unsigned int nHashCode;

		nHashCode = key.hashCode();

		unsigned int nIndex = nHashCode % m_nTableSize;

		for (HashtableEntry* entry = tab[nIndex]; entry != NULL; entry = entry->next)
		{
			if (entry->nHashCode == nHashCode && entry->key.equals(key))
			{
				pValue = &entry->value;
				break;
			}
		}

		return pValue;
	}
	else
	{
		return NULL;
	}
}

/**
 * @brief Returns the value to which the specified
 *              key is mapped in this hashtable.
 *
 * @param key   a key in the hashtable.
 * @return      the value to which the key is mapped in this
 *              hashtable; null if the key is not mapped to
 *              any value in this hashtable.
 * @see         #get(const Key& key)
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/27 - Creation
 */
template <class Key, class Value>
Value* CHashtable<Key,Value>::operator[](const Key& key) const
{
	return get(key);
}

/**
 * @brief Maps the specified key to the specified value in
 *              this hashtable. Neither the key nor the value can
 *              be null.
 *              The value can be retrieved by calling the get
 *              method with a key that is equal to the original key.
 *
 * @param key    the hashtable key.
 * @param value  the value
 * @return       the previous value of the specified key in this
 *               hashtable, or null if it did not have one.
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
void CHashtable<Key,Value>::put(const  Key& key, const Value& value)
{
	if (!m_table)
	{
		return;
	}

	HashtableEntry** tab = m_table;

	unsigned int nHashCode = 0;

	nHashCode = key.hashCode();

	unsigned int nIndex = nHashCode % m_nTableSize;

	HashtableEntry* entry;
	for (entry = tab[nIndex]; entry != NULL; entry = entry->next)
	{
		if ((entry->nHashCode == nHashCode) && entry->key.equals(key))
		{
			entry->value = value;
			return;
		}
	}

	if (m_nCount >= m_nThreshold)
	{
		rehash();
		put(key, value);
		return;
	}

	entry = new HashtableEntry();
	if (NULL == entry)
	{
		//printf("memory error! not enough memory or memory limited!");
	}
	entry->nHashCode = nHashCode;
	entry->key = key;
	entry->value = value;
	entry->next = tab[nIndex];
	tab[nIndex] = entry;
	m_nCount++;

	return;
}

/**
 * @brief Increases the capacity of and internally
 *              reorganizes this hashtable, in order to accommodate
 *              and access its entries more efficiently.
 *              This method is called automatically when the number
 *              of keys in the hashtable exceeds this hashtable's
 *              capacity and load factor.
 *
 * @return      None
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
void CHashtable<Key,Value>::rehash()
{
	unsigned int oldTableSize = m_nTableSize;
	HashtableEntry** oldTable = m_table;

	unsigned int newTableSize = nextPrime(2 * oldTableSize);
	HashtableEntry** newTable = new HashtableEntry*[newTableSize];
	if (NULL == newTable)
	{
		//printf("memory error! not enough memory or memory limited!");
	}

	unsigned int i;
	for (i = 0; i < newTableSize; i++)
	{
		newTable[i] = NULL;
	}

	m_nThreshold = (unsigned int)(newTableSize * m_fLoadFactor);
	m_table = newTable;

	for (i = 0; i < oldTableSize; i++)
	{
		for (HashtableEntry* old = oldTable[i]; old != NULL;)
		{
			HashtableEntry* entry = old;
			old = old->next;

			unsigned int nIndex = entry->nHashCode % newTableSize;
			entry->next = newTable[nIndex];
			newTable[nIndex] = entry;
		}
	}

	m_nTableSize = newTableSize;

	delete [] oldTable;
	oldTable = NULL;
}

template <class Key, class Value>
void CHashtable<Key,Value>::Freeze(bool bFreeze)
{
	m_bFreeze = bFreeze;
}

/**
 * @brief Removes the key (and its corresponding value)
 *              from this hashtable. This method does nothing
 *              if the key is not in the hashtable.
 *
 * @param key  the key that needs to be removed.
 * @return     the value to which the key had been mapped in
 *             this hashtable, or null if the key did not have
 *             a mapping.
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 *   YWF        04/06/01 - modified, set tab[nIndex] = NULL after deleted the tab[nIndex]'s entry
*/
template <class Key, class Value>
void CHashtable<Key,Value>::remove(const Key& key)
{
	HashtableEntry** tab = m_table;
	unsigned int nHashCode;

	nHashCode = key.hashCode();

	unsigned int nIndex = nHashCode % m_nTableSize;

	for (HashtableEntry* entry = tab[nIndex], *prev = NULL; entry != NULL; prev = entry, entry = entry->next)
	{
		if (entry->nHashCode == nHashCode && entry->key.equals(key))
		{
			if (prev != NULL)
			{
				prev->next = entry->next;
			}
			else
			{
				tab[nIndex] = tab[nIndex]->next;
			}

			delete entry;
			entry = NULL;

			m_nCount--;

			return ;//theReturn;
		}
	}

	return ;//valueNull;
}

/**
 * @brief Clears this hashtable so that it contains no keys.
 *
 * @return      None
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 *   YWF        04/06/01 - Modified, added set tmp = NULL, after delete tmp
 */
template <class Key, class Value>
void CHashtable<Key,Value>::clear()
{
	unsigned int i = 0;

	if (m_table)
	{
		HashtableEntry** tab = m_table;

		for (i=0; i<m_nTableSize; i++)
		{
			HashtableEntry* entry = tab[i];

			while (entry)
			{
				HashtableEntry* tmp = entry;
				entry = entry->next;
				delete tmp;
				tmp = NULL;  //because the tmp reponsing to entry isn't equal to NULL
				//if ..., then cause core dump at entry = entry->next;
			}

			tab[i] = NULL;
		}//for i
		m_nCount = 0;
	}//if m_table
}

template <class Key, class Value>
void CHashtable<Key,Value>::clearvalue(bool bValue)
{
	unsigned int i = 0;

	if (m_table)
	{
		HashtableEntry** tab = m_table;

		for (i=0; i<m_nTableSize; i++)
		{
			HashtableEntry* entry = tab[i];

			while (entry)
			{
				HashtableEntry* tmp = entry;
				entry = entry->next;
				if (bValue)
				{
					delete tmp->value;
					tmp->value = NULL;
				}
				delete tmp;
				tmp = NULL;  //because the tmp reponsing to entry isn't equal to NULL
				//if ..., then cause core dump at entry = entry->next;
			}

			tab[i] = NULL;
		}//for i
		m_nCount = 0;
	}//if m_table
}

/**
 * @brief Returns the next hashtable size. When the actual
 *              load factor reaches the load factor, the number
 *              of buckets in the Hashtable is automatically
 *              increased to the smallest prime number that is
 *              larger than twice the current number of Hashtable
 *              buckets. Choosing a prime number for the table size
 *              tends to reduce the number of collisions. A little
 *              number theory (Bertrand's Postulate) tells us that
 *              there is always a prime number between size and
 *              2 * size (size > 2).
 *
 * @param nStart  start search number which is typically twice the
 *                current number
 * @return        smallest prime number that is larger than the
 *                start number
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
unsigned int CHashtable<Key, Value>::nextPrime(unsigned int nStart)
{
	unsigned int i = 0;

	if (nStart % 2 == 0)
	{
		nStart++;
	}

	for ( ;; nStart += 2)
	{
		for (i = 3; i*i <= nStart; i += 2)
		{
		     if (nStart % i == 0)
		     {
				break;
		     }
		}

		if (i*i > nStart)
		{
		     return nStart;
		}
	}
}

/**
 * @brief Returns an enumeration of the keys in
 *              this hashtable.
 *
 * @return      an enumeration of the keys in this hashtable.
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
const Key* CHashtable<Key, Value>::keys()
{
	int elementSize = size();

	if (m_keys)
	{
		delete[] m_keys;
	}

	m_keys = new Key[elementSize];
	if (NULL == m_keys)
	{
		//printf("memory error! not enough memory or memory limited!");
	}

	HashtableEntry** tab = m_table;
	for (unsigned int i = 0; i < m_nTableSize; i++)
	{
		for (HashtableEntry* entry = tab[i]; entry != NULL; entry = entry->next)
		{
			m_keys[--elementSize] = entry->key;
		}
	}
	return m_keys;
}

/**
 * @brief Returns an enumeration of the values in this
 *              hashtable. Use the Enumeration methods on the
 *              returned object to fetch the elements sequentially.
 *
 * @return      an enumeration of the values in this hashtable.
 *
 * ChangeLog:
 *   Modified   yy/mm/dd
 *   ZTP        03/09/26 - Creation
 */
template <class Key, class Value>
const Value* CHashtable<Key, Value>::elements()
{
	HashtableEntry** tab = m_table;

	int elementSize = size();

	if (m_elements)
	{
		delete[] m_elements;
	}
	m_elements = new Value[elementSize];
	if (NULL == m_elements)
	{
		//printf("memory error! not enough memory or memory limited!");
	}

	for (unsigned int i = 0; i < m_nTableSize; i++)
	{
		for (HashtableEntry* entry = tab[i]; entry != NULL; entry = entry->next)
		{
			m_elements[--elementSize] = entry->value;
		}
	}
	return m_elements;
}


template <class Key, class Value>
void CHashtable<Key, Value>::TravelInit(int& nTravelHead, void **pTravelEntry)
{
	assert(NULL != pTravelEntry);
	nTravelHead = 0;
	(*pTravelEntry) = (void*)m_table[nTravelHead];
}

template <class Key, class Value>
Value* CHashtable<Key, Value>::GetNextElement(int& nTravelHead, void **pTravelEntry, Key& key)
{
	Value         *value = NULL;
	unsigned int   nhead = nTravelHead;
	HashtableEntry *pEntry = (HashtableEntry*)(*pTravelEntry);

	while(nhead < m_nTableSize)
	{
		while(pEntry != NULL)
		{
			key = pEntry->key;
			value = &pEntry->value;

			pEntry = pEntry->next;

			nTravelHead = nhead;
			(*pTravelEntry) = (void *)pEntry;

			return value;
		}

		nhead++;

		if(nhead < m_nTableSize)
		{
			pEntry = m_table[nhead];
		}
	}

	return NULL;
}

template <class Key, class Value>
void CHashtable<Key,Value>::init(unsigned int initialCapacity,
                                  float loadFactor,
                                  bool bAutoDelete)
{
	unsigned int i = 0;

	if (loadFactor <= 0.0 || loadFactor >= 1.0)
	{
		//printf( "Bad Argument for loadFactor\n" );
		exit(1);
	}

	m_nCount = 0;
	m_nTableSize = initialCapacity;
	m_fLoadFactor = loadFactor;
	m_nThreshold = (unsigned int)(initialCapacity * loadFactor);

	m_table = new HashtableEntry*[m_nTableSize];
	if (NULL == m_table)
	{
		//printf("memory error! not enough memory or memory limited!");
		exit(-1);
	}

	for( i = 0; i < m_nTableSize; i++ )
	{
		m_table[i] = NULL;
	}

	m_keys = NULL;
	m_elements = NULL;

	m_bFreeze = false;
}

template <class Key, class Value>
void CHashtable<Key, Value>::reset(unsigned int initialCapacity ,
		   float loadFactor, bool bAutoDelete)
{
    assert(m_nCount==0);

	if (m_table)
	{
		delete[] m_table;
		m_table = NULL;
	}

	if (m_keys)
	{
		delete[] m_keys;
		m_keys = NULL;
	}

	if (m_elements)
	{
		delete[] m_elements;
	}

	m_elements = NULL;

    init(initialCapacity,loadFactor, bAutoDelete);
    return;

}

//		} /* sdata */
//	} /* library */
//} /* lspublic */

#endif
