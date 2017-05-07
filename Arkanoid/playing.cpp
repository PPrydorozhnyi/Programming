#include "playing.h"
#include "ui_playing.h"

#include <QDebug>

Playing::Playing(QWidget *parent) :
    ActiveWindow(parent),
    ui(new Ui::Playing)
{
    ui->setupUi(this);
    resize(860,660);
    setFixedSize(860,660);

    //button = new ButtonWidget(this,  QStringLiteral ("Menu"));
    //button->setGeometry(700, 285, 60, 50 );

    m_x = 0;
    m_gameOver = false;
    m_gameStated = false;
    m_gameWon = false;
    m_paused = false;

    ball = new Ball();
    paddle = new Paddle();

    int counter = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++ ) {
            bricks[counter] = new Brick(j * 100 + 100, i * 40 + 100);
            counter++;
        }

    setFocusPolicy(Qt::ClickFocus);
}


Playing::~Playing()
{
    onDelete();

    delete ball;
    delete paddle;

    for (int i = 0; i < AMOUNT_OF_BRICKS; i++)

        delete bricks[i];

    delete ui;
}

void Playing::paintEvent(QPaintEvent *)
{
    //QRectF source(0.0, 0.0, 860, 660);
    //QImage image(":/MyRes/playing.png");

    //QPainter painter1(this);
    //painter1.drawImage(source,image);

    QPainter painter(this);

    if (m_gameOver)
        onFinishGame(&painter, "Game over");
    else if (m_gameWon)
        onFinishGame(&painter, "You Won");
    else
        drawObjects(&painter);

}

void Playing::onFinishGame(QPainter *painter, QString message) {

    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fontM(font);
    int textWidth = fontM.width(message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w / 2, h / 2));
    painter->drawText(-textWidth / 2, 0, message);

    qDebug() << "Game finished";

}

void Playing::drawObjects(QPainter *painter) {

    painter->drawImage(ball->getRect(), ball->getImage());
    painter->drawImage(paddle->getRect(), paddle->getImage());

    for (int i = 0; i < AMOUNT_OF_BRICKS; i++) {

        if (!bricks[i]->isDestroyed())

            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());

    }

}

void Playing::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event);

    moveObjects();
    checkCollisions();
    repaint();

}

void Playing::moveObjects() {

    ball->autoMove();
    paddle->move();

}

void Playing::keyPressEvent(QKeyEvent * event)
{

    int dx = 0;

    switch (event->key() ) {

    case Qt::Key_Left:

        dx = -2;
        paddle->setDeltaX( dx );

        break;

    case Qt::Key_Right:

        dx = 2;
        paddle->setDeltaX( dx );

        break;

    case Qt::Key_Space:

        startGame();
        break;

    case Qt::Key_P:

        pauseGame();
        break;

    case Qt::Key_Escape:

        stopGame();
        emit clicked(true);

        break;

    default:

        QWidget::keyPressEvent(event);

    }

}

void Playing::keyReleaseEvent(QKeyEvent * event)
{

    int dx = 0;

    switch (event->key()) {

    case Qt::Key_Left:
    case Qt::Key_Right:
        dx = 0;
        paddle->setDeltaX(dx);
        break;

    }

}

void Playing::startGame() {

    if (!m_gameStated) {

        ball->resetState();
        paddle->resetState();

        for (int i = 0; i < AMOUNT_OF_BRICKS; i++)
            bricks[i]->setDestroyed(false);

        m_gameOver = false;
        m_gameWon = false;
        m_gameStated = true;
        m_timerId = startTimer(DELAY);

        qDebug() << "Game started";

    }

}

void Playing::pauseGame() {

    if (m_paused) {

        m_timerId = startTimer(DELAY);
        m_paused = false;

        qDebug() << "Game unpaused";

    } else {

        m_paused = true;
        killTimer(m_timerId);

        qDebug() << "Game paused";

    }

}

void Playing::stopGame() {

    killTimer(m_timerId);
    m_gameOver = true;
    m_gameStated = false;

    qDebug() << "Game stoped";

}

void Playing::flawlessVictory() {

    killTimer(m_timerId);
    m_gameWon = true;
    m_gameStated = false;

    qDebug() << "Victory";

}

void Playing::checkCollisions() {

    if (ball->getRect().bottom() > BOTTOM_EDGE)

        stopGame();

    for (int i = 0, j = 0; i < AMOUNT_OF_BRICKS; i++) {

        if (bricks[i]->isDestroyed())
            j++;

        if (j == AMOUNT_OF_BRICKS)
            flawlessVictory();
    }

    if ( (ball->getRect()).intersects(paddle->getRect()) ) {

        int paddlePos = paddle->getRect().left();
        int ballPos = ball->getRect().left();

        //qDebug() << paddle->getRect();

        // set angles of deviation
        int first = paddlePos + 16;
        int second = paddlePos + 32;
        int third = paddlePos + 48;
        int fourth = paddlePos + 64;

        if (ballPos < first) {

            ball->setX(-1);
            ball->setY(-1);

        } else if (ballPos >= first && ballPos < second) {

            ball->setX(-1);
            ball->setY(-1 * ball->getY());

        } else if (ballPos >= second && ballPos < third) {

            ball->setX(0);
            ball->setY(-1);

        } else if (ballPos >= third && ballPos <= fourth) {

            ball->setX(1);
            ball->setY(-1 * ball->getY());

        } else if (ballPos > fourth) {

            ball->setX(1);
            ball->setY(-1);

        }
    }


        for (int i = 0; i < AMOUNT_OF_BRICKS; i++) {

            //qDebug() << "Bricks";

            if ( (ball->getRect() ).intersects(bricks[i]->getRect()) ) {

                //qDebug() << "Brick should be destriyed";

                int ballX = ball->getRect().x();
                int ballWidth = ball->getRect().width();
                int ballY = ball->getRect().y();
                int ballHeight = ball->getRect().height();

                //before intersects for ball, intersects points
                QPoint pointLeft1(ballX - 1, ballY);
                QPoint pointLeft2(ballX - 1, ballY + ballHeight);
                QPoint pointRight1(ballX + ballWidth +1, ballY);
                QPoint pointRight2(ballX + ballWidth +1, ballY + ballHeight);
                QPoint pointTop1(ballX, ballY - 1);
                QPoint pointTop2(ballX + ballWidth, ballY - 1);
                QPoint pointBottom1(ballX, ballY + ballHeight + 1);
                QPoint pointBottom2(ballX + ballWidth, ballY + ballHeight + 1);

                if (!bricks[i]->isDestroyed()) {
                    if (bricks[i]->getRect().contains(pointRight1) || bricks[i]->getRect().contains(pointRight2)) {

                        ball->setX(-1);
                        qDebug() << "pointRight";

                    }

                    else if (bricks[i]->getRect().contains(pointLeft1) || bricks[i]->getRect().contains(pointLeft2)) {

                        ball->setX(1);
                        qDebug() << "pointLeft";
                    }

                    if (bricks[i]->getRect().contains(pointTop1) || bricks[i]->getRect().contains(pointTop2)) {

                        ball->setY(1);
                        qDebug() << "pointTop";
                    }

                    else if (bricks[i]->getRect().contains(pointBottom1) || bricks[i]->getRect().contains(pointBottom2)) {

                        ball->setY(-1);
                        qDebug() << "pointBottom";
                    }

                    bricks[i]->setDestroyed(true);

                    //qDebug() << "Brick destroyed";
                }


            }

        }

}

void Playing::run()
{

}
