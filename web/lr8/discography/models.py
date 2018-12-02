from django.db import models
from django.utils.text import slugify
from django.shortcuts import reverse


class Musician(models.Model):
    name = models.CharField(verbose_name="Название исполнителя",
                            max_length=25)
    information = models.TextField(verbose_name="Информация о исполнителе",
                                   blank=True,
                                   null=True)
    slug = models.SlugField(max_length=25,
                            blank=True,
                            unique=True)
    date_pub = models.DateTimeField(auto_now_add=True)

    def get_absolute_url(self):
        return reverse("musician_read_url", kwargs={"slug": self.slug})

    def get_update_url(self):
        return reverse("musician_update_url", kwargs={"slug": self.slug})

    def get_delete_url(self):
        return reverse("musician_delete_url", kwargs={"slug": self.slug})

    def save(self, *args, **kwargs):
        if not self.id:
            self.slug = slugify(self.name)
        super().save(*args, **kwargs)

    def __str__(self):
        return self.name

    class Meta:
        verbose_name = "Исполнитель"
        verbose_name_plural = "Исполнители"


class Song(models.Model):
    GENRE_CHOICES = {
        ("Classical music", "Classical music"),
        ("Electonic music", "Electonic music"),
        ("Rap", "Rap"),
        ("Rock", "Rock"),
    }

    name = models.CharField(verbose_name="Название песни",
                            max_length=25)
    slug = models.SlugField(max_length=25,
                            blank=True,
                            unique=True)
    album = models.CharField(verbose_name="Альбом",
                             max_length=25)
    genre = models.CharField(verbose_name="Жанр",
                             max_length=25,
                             choices=GENRE_CHOICES)
    musician = models.ForeignKey("Musician",
                                 verbose_name="Исполнитель",
                                 related_name="musician_songs",
                                 on_delete="CASCADE")
    lyrics = models.TextField(verbose_name="Текст песни",
                              blank=True,
                              null=True)
    lyrics_ru = models.TextField(verbose_name="Текст песни на русском",
                                 blank=True,
                                 null=True)

    def get_absolute_url(self):
        return reverse("song_read_url", kwargs={"slug": self.slug})

    def get_update_url(self):
        return reverse("song_update_url", kwargs={"slug": self.slug})

    def get_delete_url(self):
        return reverse("song_delete_url", kwargs={"slug": self.slug})

    def save(self, *args, **kwargs):
        if not self.id:
            self.slug = slugify(self.name)
        super().save(*args, **kwargs)

    def __str__(self):
        return self.name

    class Meta:
        verbose_name = "Песня"
        verbose_name_plural = "Песни"
