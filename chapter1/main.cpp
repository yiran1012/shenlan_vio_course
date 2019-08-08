#include <iostream>
#include <Eigen/Eigen>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <sophus/so3.h>

int main(int argc, char **argv) {
    using namespace std;

    Eigen::Matrix3d init_R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    cout<<"初始旋转矩阵为： \n"<<init_R<<endl;

    Eigen::Vector3d w(0.01,0.02,0.03);
    cout<<"更新向量为： \n"<<w.transpose()<<endl;

    Sophus::SO3 dR = Sophus::SO3::exp(w);
    Eigen::Quaterniond dq_R = dR.unit_quaternion();
    Eigen::Quaterniond dq = Eigen::Quaterniond(1, 0.5*0.01, 0.5*0.02, 0.5*0.03).normalized();

    cout<<"通过R的更新量为： \n"<<dq_R.coeffs().transpose()<<endl;
    Sophus::SO3 SO3_R(init_R);
    Sophus::SO3 R_updated_by_dR = dR*SO3_R;
    cout<<"通过R更新后的旋转矩阵为： \n"<<R_updated_by_dR.matrix()<<endl;
    cout<<"通过q的更新量为： \n"<<dq.coeffs().transpose()<<endl;
    Sophus::SO3 SO3_dq(dq);
    Sophus::SO3 R_updated_by_dq = SO3_dq*SO3_R;
    cout<<"通过q更新后的旋转矩阵为： \n"<<R_updated_by_dq.matrix()<<endl;

    //四元数表示
    Eigen::Quaterniond q_updated_by_dR = Eigen::Quaterniond(R_updated_by_dR.matrix());
    cout<<"通过R更新后的四元数为： \n"<<q_updated_by_dR.coeffs().transpose()<<endl;
    Eigen::Quaterniond q_updated_by_dq = Eigen::Quaterniond(R_updated_by_dq.matrix());
    cout<<"通过q更新后的四元数为： \n"<<q_updated_by_dq.coeffs().transpose()<<endl;

    return 0;
}