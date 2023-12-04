1、掌握数据库系统的基本概念 包括三层模式结构与两级映像 数据独立性等

	数据库
		文件系统 数据冗余 数据不一致 数据联系弱

	数据描述
		概念模式 实体 实体集 属性 实体标识符
		逻辑设计 字段 记录 文件 关键码
		数据联系的描述 二元联系

	数据抽象级别
		概念模型 ER模型
		逻辑模型 层次模型 网状模型 关系模型 对象模型
		外部模型 识图
		内部模型
		三级模式两级映像

	数据库管理
		数据库定义 DDL
		数据库操纵 DML
		保护 维护 字典

	数据库系统
		用户
		DBMS 查询处理器 DDL解释器 DDL编译器 DML预编译器 查询求值器
		DBMS 存储管理器 权限和完整性管理器 事务管理器 文件管理器 缓冲区管理器
		磁盘中的数据结构 数据文件 数据字典 索引 统计数据 日志

2、掌握关系模型的基本概念，熟练掌握关系代数运算和关系代数表达式的优化。

	关系模型
		二维表格表示实体集
		关键码表示联系
			属性值 属性 关系模式 元组 属性的个数是元数 元组的个数是基数
		完整性规则
			实体完整性规则
			参照完整性规则
			用户定义CHECK
		关系模式
			模式名 属性名 域名 模式主键
		子模式 存储模式
	关系代数
		并 差 笛卡尔积x 投影pai 选择σ
		交 连接 自然连接 除
		聚集
	关系代数表达式的优化
		选择-投影-笛卡尔积

3、熟练掌握关系数据库语言SQL，包括数据定义、数据查询、数据更新、视图及索引的使用。

	//数据定义
	CREATE TABLE T(
		T# CHAR(4) NOT NULL,
		TNAME CHAR(12) NOT NULL,
		TITLE CHAR(10),
		PRIMARY KEY(T#));

	CREATE TABLE C(
		C# CHAR(4) NOT NULL,
		CNAME CHAR(8) NOT NULL,
		T# CHAR(4),
		PRIMARY KEY(C#),
		FOREIGN KEY(T#) REFERENCES T(T#));

	CREATE TABLE S(
		S# CHAR(4) NOT NULL,
		SNAME CHAR(12) NOT NULL,
		AGE SMALLINT,
		SEX CHAR(1),
		PRIMARY KEY(S#));

	CREATE TABLE SC(
		S# CHAR(4);
		C# CHAR(4);
		SCORE SMALLINT,
		PRIMARY KEY(S#,C#),
		FOREIGN KEY(S#) REFERENCES S(S#),
		FOREIGN KEY(C#) REFERENCES C(C#));

	//DROP TABLE S;
	//
	ALTER TABLE S ADD AGE CHAR(4);
	ALTER TABLE S DROP AGE;
	ALTER TABLE S MODIFY AGE CHAR(6);

	//数据查询
	SELECT S.S#,SNAME FROM S,SC WHERE S.S# = SC.S# AND C# = 'C2';
	SELECT S#,SNAME FROM S WHERE S# IN(SELECT S# FROM SC WHERE C# = 'C2');
	SELECT S#,NAME FROM S WHERE 'C2' IN (SELECT S# FROM SC WHERE S# = S.S#);
	SELECT S#,NAME FROM S WHERE EXIST (SELECT * FROM SC WHERE SC.S# = S.S# AND C# = 'C2');
	SELECT X.S# WHERE SC AS X, SC AS Y WHERE X.S# = Y.S# AND C.C# = 'C2' AND Y.C# = 'C4';
	SELECT DISTINCT S# FROM SC AS X WHERE NOT EXISTS (SELECT * FROM SC AS Y WHERE Y.S# = 'S3' AND NOT EXISTS(SELECT * FROM SC AS Z WHERE Z.S# = X.S# AND Z.C# = Y.C#))

	SELECT T#,C.C#,COUNT(S#) FROM C,SC WHERE C.C# = SC.C# GROUP BY T#,C.C# HAVING COUNT(*) > 50 ORDER BY 3,T#,C.C#;
	SELECT COUNT(S#) + 100,COUNT(*),SUM(S#),AVG(S#),MAX(S#),MIN(S#) FROM S,SC WHERE S.S# = SC.S# AND C# = 'C2';

	(SELECT S.S#,SNAME FROM S,SC WHERE S.S# = SC.S# AND C# = 'C2') UNION (INTERSECT EXCEPT) [ALL]
	(SELECT S.S#,SNAME FROM S,SC WHERE S.S# = SC.S# AND C# = 'C2')
	//数据更新
	INSERT INTO S[(S#)] VALUES('1','1','1'),('1','1','1');
	INSERT INTO S[(S#)] SELECT S.S#,SNAME FROM S,SC WHERE S.S# = SC.S# AND C# = 'C2';
	INSERT INTO S[(S#)] TABLE S;
	DELETE FROM S [WHERE]
	UPDATE C SET CNAME = 'DB' WHERE C# = 'C5';

	//索引
	CREATE [UNIQUE] INDEX S#_INDEX ON S(S#)
	DROP INDEX S#_INDEX

	//视图
	CREATE VIEW STU_S (S#,SNAME,CNAME,SCORE) WITH CHECK OPTION
	AS SELECT S.S#,SNAME,CNAME,SCORE FROM S,SC,C WHERE S.S# = SC.S# AND SC.C# = C.C#;

	DROP VIEW STU_S;

4、掌握函数依赖、第一范式、第二范式、第三范式和BC范式等概念，熟练判断关系模式的范式、进行关系模式的无损连接分解与保持函数依赖分解。

	函数依赖 一对多联系 一依赖于多
		FD推理准则 自反增广传递 合并分解复合 伪传递
		闭包 最小依赖集
	无损链接分解 chase方法 保持依赖分解 投影方法
	范式 1NF 规范化关系
		2NF 解决非主属性对主属性部份依赖
		3NF 解决非主属性对主属性传递依赖
		BCNF 解决主属性对主属性的传递依赖

5、理解数据库设计的全过程，熟练掌握ER模型，以及 ER模型到关系模型的转换。

	数据库的设计过程
		规划 需求分析 概念设计 逻辑设计 物理设计 实现 运行维护
		需求分析
			业务流程图 系统关联图 数据流图 数据字典
		概念设计阶段
		逻辑设计阶段
			把概念模型转化为逻辑模型 设计外模式 设计应用程序与数据库的接口 评价模型 修正模型
		物理设计阶段
		数据库的实现
			定义数据库的结构 数据装载 编制与调试应用程序 数据库试运行
		数据库的运行与维护
			数据库的转储和恢复 数据库安全性，完整性控制 数据库的监督分析和改进 数据库的重组织和重构造
	ER模型
		实体集 联系 属性
			简单属性和复合属性 单值属性和多值属性 存储属性和派生属性
		ER模型转化为关系模型
			1:1 两个实体类型转化为两个关系模式，一个加入另一个的键 和 联系类型的属性
			1:N N端加入1端的 键 和 联系类型的属性
			M:N 把联系类型也转换成关系模式 属性是两端实体 的 键 加上联系类型的属性 键是两端实体的键
		逻辑设计步骤
			导出初始关系模式集 规范化 评价 修正 子模式


6、掌握事务的概念和ACID性质，理解数据库的恢复、并发控制、完整性约束、安全性保护方法，能够使用SQL创建用户和授权。

	事务：构成单一逻辑工作单元的操作集合
	提交：事务成功结束
	回退：事务执行不成功的结束

	ACID性质
		原子性：事务管理子系统：事务不可分割
		一致性：完整性子系统：数据不会因事务的执行遭到破坏
		隔离性：并发控制子系统：保证多个并发事务的执行与先后单独执行一致
		持久性：恢复管理子系统：事务一旦完成，对数据库的更改要永久反映在数据库内

		事务的状态变迁：活动，局部提交，提交，失败，异常中止

	数据库的恢复
		转储和建立日志
			物理破坏：重做
			数据不一致：撤销与重做
		故障类型
			事务故障
			系统故障
			介质故障
		检查点

	并发控制
		并发操作的问题
			丢失更新
			读脏数据
			不可重复读
		封锁级数
			X锁 排他锁
			S锁 共享锁
			封锁协议
				修改数据前加X锁
				一级 读数据不加锁 解决丢失修改
				二级 读数据加S锁，读完释放 又解决读脏数据
				三级 读加S锁，事务结束释放 又解决不可重复读
			封锁问题
				活锁 一直等待，无法封锁
				饿死 永远无法封锁
				死锁 两个事务锁对方的资源

	完整性
		完整性子系统
			正确性 有效性 相容性
		完整性约束
			域约束 CHECK DOMAIN COLOR CHAR(6) DEFAULT'???'
			基本表约束
				CONSTRAINT VALID_COLORS
				CHECK(VALUE IN ('RED','???'))
				PRIMARY KEY()
				FOREIGN KEY()REFERENCE()
			断言约束

	安全
		权限
			访问数据 读取插入修改删除
			修改数据库模式 索引资源修改撤销

		安全性机制
			视图 权限 角色 审计
				GRANT  <权限> ON <表> TO <用户> [WITH CHECK OPTION]
				权限 USAGE 使用已经定义过的域
				SELECT INSERT DELETE UPDATE REFERENCES
		安全性措施
			强制存取控制
			数据库的安全性
			数据加密法

