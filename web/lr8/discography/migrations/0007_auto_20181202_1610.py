# Generated by Django 2.1.3 on 2018-12-02 06:10

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('discography', '0006_auto_20181202_0038'),
    ]

    operations = [
        migrations.AlterField(
            model_name='song',
            name='genre',
            field=models.CharField(choices=[('Electonic music', 'Electonic music'), ('Rock', 'Rock'), ('Rap', 'Rap'), ('Classical music', 'Classical music')], max_length=25, verbose_name='Жанр'),
        ),
    ]
