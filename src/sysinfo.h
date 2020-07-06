#ifndef SYSINFO_H
#define SYSINFO_H

#include <QObject>
#include <QSysInfo>

class SysInfo : public QObject {
  Q_OBJECT

  Q_PROPERTY(QString buildAbi READ buildAbi WRITE setBuildAbi NOTIFY buildAbiChanged)
  Q_PROPERTY(QString cpuArch READ cpuArch WRITE setCpuArch NOTIFY cpuArchChanged)
  Q_PROPERTY(QString uniqueID READ uniqueID WRITE setUniqueID NOTIFY uniqueIDChanged)
  Q_PROPERTY(QString kernelType READ kernelType WRITE setKernelType NOTIFY kernelTypeChanged)
  Q_PROPERTY(QString kernelVersion READ kernelVersion WRITE setKernelVersion NOTIFY kernelVersionChanged)
  Q_PROPERTY(QString hostName READ hostName WRITE setHostName NOTIFY hostNameChanged)
  Q_PROPERTY(QString productName READ productName WRITE setProductName NOTIFY productNameChanged)
  Q_PROPERTY(QString productType READ productType WRITE setProductType NOTIFY productTypeChanged)
  Q_PROPERTY(QString productVersion READ productVersion WRITE setProductVersion NOTIFY productVersionChanged)

 public:
  explicit SysInfo(QObject *parent = nullptr);
  SysInfo(const SysInfo &sysInfo);
  //! Returns the full architecture string that Qt was compiled for.
  QString buildAbi() const { return m_buildAbi; }
  //! Returns the architecture of the CPU that the application is running on, in text format.
  QString cpuArch() const { return m_cpuArch; }
  //! Returns the type of the operating system kernel Qt was compiled for.
  QString kernelType() const { return m_kernelType; }
  //! Returns the release version of the operating system kernel.
  QString kernelVersion() const { return m_kernelVersion; }
  //! Returns this machine's host name, if one is configured.
  QString hostName() const { return m_hostName; }
  //! Returns a prettier form of productType() and productVersion(),
  //! containing other tokens like the operating system type, codenames and other information.
  QString productName() const { return m_productName; }
  //! Returns the product name of the operating system this application is running in.
  QString productType() const { return m_productType; }
  //! Returns the product version of the operating system in string form.
  QString productVersion() const { return m_productVersion; }
  //! Returns a unique ID for this machine, if one can be determined.
  QString uniqueID() const { return m_uniqueID; }
  //! Operator overloading to compare two SysInfo classes
  bool operator==(const SysInfo &sysInfo);
  //! Operator overload to assign the value of sysInfo on this object
  SysInfo &operator=(const SysInfo &sysInfo);
  //! Return the object itself
  Q_INVOKABLE SysInfo &objectItSelf(void);

 public slots:
  //!
  void setBuildAbi(QString buildAbi);
  //!
  void setCpuArch(QString cpuArch);
  //!
  void setKernelType(QString kernelType);
  //!
  void setKernelVersion(QString kernelVersion);
  //!
  void setHostName(QString hostName);
  //!
  void setProductName(QString productName);
  //!
  void setProductType(QString productType);
  //!
  void setProductVersion(QString productVersion);
  //!
  void setUniqueID(QString uniqueID);

 signals:
  void buildAbiChanged(QString buildAbi);
  void cpuArchChanged(QString cpuArch);
  void kernelTypeChanged(QString kernelType);
  void kernelVersionChanged(QString kernelVersion);
  void hostNameChanged(QString hostName);
  void productNameChanged(QString productName);
  void productTypeChanged(QString productType);
  void productVersionChanged(QString productVersion);
  void uniqueIDChanged(QString uniqueID);

 private:
  QString m_buildAbi;
  QString m_cpuArch;
  QString m_kernelType;
  QString m_kernelVersion;
  QString m_hostName;
  QString m_productName;
  QString m_productType;
  QString m_productVersion;
  QString m_uniqueID;
};

#endif  // SYSINFO_H
