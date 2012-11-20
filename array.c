#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_peanut_php.h"

PHP_FUNCTION(peanut_array_keys)
{
    zval *array, **data,  *temp_key;
    char *key, *temp;
    HashTable *arr_hash;
    HashPosition pointer;
    int array_len, key_len;
    long num_key;
    array_init(return_value);
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &array, &array_len) == FAILURE)
    {
        RETUTN_NULL();
    }
    
    arr_hash = Z_ARRVAL_P(array);
    zend_hash_internal_pointer_reset_ex(arr_hash, &pointer);
    while (zend_hash_get_current_data_ex(arr_hash, (void**)&data, &pointer) == SUCCESS)
    {
        MAKE_STD_ZVAL(temp_key);
        key_len = 0;
        switch (zend_hash_get_current_key_ex(arr_hash, &key, &key_len, &num_key, 1, &pointer))
        {
            case HASH_KEY_IS_STRING:
                ZVAL_STRINGL(temp_key, key, key_len, 0);
                add_next_index_zval(return_value, temp_key);
                break;
            case HASH_KEY_IS_LONG:
                Z_TYPE_P(temp_key) = IS_LONG;
                Z_LVAL_P(temp_key) = num_key;
                add_next_index_zval(return_value, temp_key);
        }
        zend_hash_move_forward_ex(arr_hash, &pointer);
    }


    
    
    
}
