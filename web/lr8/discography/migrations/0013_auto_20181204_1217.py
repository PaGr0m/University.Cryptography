# Generated by Django 2.1.3 on 2018-12-04 02:17

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('discography', '0012_auto_20181203_1815'),
    ]

    operations = [
        migrations.AlterField(
            model_name='song',
            name='genre',
            field=models.CharField(choices=[('Rock', 'Rock'), ('Rap', 'Rap'), ('Classical music', 'Classical music'), ('Electonic music', 'Electonic music')], max_length=25, verbose_name='Жанр'),
        ),
    ]