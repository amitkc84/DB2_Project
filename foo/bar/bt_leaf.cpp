// File name : bt_leaf.cpp
// Date : 03/06/3013
// Team : Amit & Mike


# include "bt_leaf.h"

/*
public:
        BtreeLeaf()
        {
                set_type(LEAF);
                set_keyCount(0);
                //include all other initializations here
        };

        ~BtreeLeaf();

        //insert to node, key of type KeyId and keyCount-int
        Status insertKey(KeyId, int);

        Status deleteKey(KeyId, int);

        Status searchKey(KeyId, int);


*/


BtreeLeaf::~BtreeLeaf() {

}

//AMIT
Status BtreeLeaf::insertKey(KeyId KeyValue, int x) {
	int KeyCount = get_keyCount();
	if(KeyCount == MAX_NUM_KEYS)	
		return LEAF_IS_FULL;
	else {
		for(int i = 0; i< MAX_NUM_KEYS; i++) {
			if(KeyValue <= key[i] || key[i] == -1) {
				int shift = MAX_NUM_KEYS - (i + 1);
				int j = 1;
				while(j <= shift ) {
				  key[MAX_NUM_KEYS-j] = key[MAX_NUM_KEYS-j-1];
				  j++;
				}
				key[i]=KeyValue;
				set_keyCount(KeyCount+1);
				return OK;
			}	
		}
	}
	return OK;
}

Status BtreeLeaf::deleteKey(KeyId, int) {
	return OK;

}

Status BtreeLeaf::searchKey(KeyId key, int *pos) {

  int i;

  for(i = 0; i < get_keyCount(); i++){
    if(getKey(i) >= key){
      *pos = i;
      return OK;
    }
  }

  return KEY_NOT_FOUND;

}





