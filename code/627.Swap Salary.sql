UPDATE salary SET sex = CASE 
  WHEN sex='f' THEN 'm'
  WHEN sex='m' THEN 'f'
END

-- 通过与或
-- update salary set sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex));