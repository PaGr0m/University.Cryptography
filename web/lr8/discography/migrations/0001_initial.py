# Generated by Django 2.1.3 on 2018-11-28 16:06

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Musician',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=25, verbose_name='Название исполнителя')),
                ('information', models.TextField(blank=True, null=True, verbose_name='Информация о исполнителе')),
                ('slug', models.SlugField(blank=True, max_length=25, unique=True)),
                ('date_pub', models.DateTimeField(auto_now_add=True)),
            ],
            options={
                'verbose_name': 'Исполнитель',
                'verbose_name_plural': 'Исполнители',
            },
        ),
        migrations.CreateModel(
            name='Song',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=25, verbose_name='Название песни')),
                ('album', models.CharField(max_length=25, verbose_name='Альбом')),
                ('genre', models.CharField(choices=[('Electonic music', 'Electonic music'), ('Rock', 'Rock'), ('Rap', 'Rap'), ('Classical music', 'Classical music')], max_length=25, verbose_name='Жанр')),
                ('lyrics', models.TextField(blank=True, null=True, verbose_name='Текст песни')),
                ('lyrics_ru', models.TextField(blank=True, null=True, verbose_name='Текст песни на русском')),
                ('musician', models.ForeignKey(on_delete='CASCADE', related_name='musician_songs', to='discography.Musician', verbose_name='Исполнитель')),
            ],
            options={
                'verbose_name': 'Песня',
                'verbose_name_plural': 'Песни',
            },
        ),
    ]
