#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>


ssize_t simple_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

ssize_t simple_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return length;
}

struct file_operations fo = {
    .owner = THIS_MODULE,
    .read = simple_read,
    .write = simple_write,
};

int __init simple_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

    register_chrdev(0, "Simple char device", &fo);
    return 0;
}

void simple_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

module_init(simple_init);
module_exit(simple_exit);
