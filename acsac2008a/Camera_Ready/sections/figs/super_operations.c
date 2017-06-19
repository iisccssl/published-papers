struct super_operations 
{
    void (*read_inode) (struct inode *);
    void (*read_inode2) (struct inode *, void *) ;
    void (*dirty_inode) (struct inode *);
    void (*write_inode) (struct inode *, int);
    void (*put_inode) (struct inode *);
    void (*delete_inode) (struct inode *);
    void (*put_super) (struct super_block *);
    void (*write_super) (struct super_block *);
    void (*write_super_lockfs) (struct super_block *);
		... More function pointers ...
}

