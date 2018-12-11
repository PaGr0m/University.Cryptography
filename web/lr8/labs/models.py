from django.db import models
from django.utils.text import slugify
from django.contrib.postgres.fields import ArrayField


class Order(models.Model):
    DELIVERY_CHOICES = {
        ("Быстрая", "Быстрая"),
        ("Бесплатная", "Бесплатная"),
    }

    DISK_CHOICES = {
        ("DVD", "DVD"),
        ("CD", "CD"),
    }

    COURSE_CHOICES = {
        ("Курсу по Фотошопу", "Курсу по Фотошопу"),
        ("Курсы по Adobe Dreamweawer", "Курсы по Adobe Dreamweawer"),
        ("Курсы по PHP", "Курсы по PHP"),
    }

    fio = models.CharField(verbose_name="ФИО",
                           max_length=30)
    password = models.CharField(verbose_name="Пароль",
                                max_length=10)
    disk = models.CharField(verbose_name="Диск",
                            max_length=3,
                            choices=DISK_CHOICES)
    course = models.CharField(verbose_name="Курсы",
                              max_length=30,
                              choices=COURSE_CHOICES)
    delivery = models.CharField(verbose_name="Способ доставки",
                                max_length=20,
                                choices=DELIVERY_CHOICES)
    address = models.TextField(verbose_name="Введите адрес доставки")
    slug = models.SlugField(max_length=25,
                            blank=True,
                            unique=True)

    def save(self, *args, **kwargs):
        if not self.id:
            self.slug = slugify(self.fio)
        super().save(*args, **kwargs)

    def __str__(self):
        return self.slug

    class Meta:
        verbose_name = "Заказ"
        verbose_name_plural = "Заказы"


class ImageModel(models.Model):
    image = models.ImageField(upload_to='')

    def save(self, *args, **kwargs):
        super().save(*args, **kwargs)


class MailModel(models.Model):
    fio = models.CharField(verbose_name="ФИО",
                           max_length=30)
    message = models.CharField(verbose_name="Сообщение",
                               max_length=30)


class Auth(models.Model):
    login = models.CharField(verbose_name="Логин",
                             max_length=30)
    password = models.CharField(verbose_name="Пароль",
                                max_length=30)


class RegExpModel(models.Model):
    form_1 = models.CharField(verbose_name="Форма 1", max_length=30)
    form_2 = models.CharField(verbose_name="Форма 2", max_length=30)
    form_3 = models.CharField(verbose_name="Форма 3", max_length=30)
    form_4 = models.CharField(verbose_name="Форма 4", max_length=30)
    form_5 = models.CharField(verbose_name="Форма 5", max_length=30)
    form_6 = models.CharField(verbose_name="Форма 6", max_length=30)
    form_7 = models.CharField(verbose_name="Форма 7", max_length=30)
    form_8 = models.CharField(verbose_name="Форма 8", max_length=30)
    form_9 = models.CharField(verbose_name="Форма 9", max_length=30)
