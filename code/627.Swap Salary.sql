UPDATE salary SET sex = CASE 
  WHEN sex='f' THEN 'm'
  WHEN sex='m' THEN 'f'
END

-- ͨ�����
-- update salary set sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex));